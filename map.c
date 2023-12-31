/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:32:44 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/31 15:40:52 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_height(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if (count == 0 && (map[0] >= '0' && map[0] <= '9'))
	{
		return (1);
	}
	return (count);
}

int	get_map_width(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (num_or_alph(map[i]))
		count++;
	while (map[i] && map[i] != '\n')
	{
		if (num_or_alph(map[i]) && map[i + 1] == ' ')
			count++;
		i++;
	}
	if ((count == 0) && (map[0] >= '0' && map[0] <= '9'))
	{
		return (1);
	}
	return (count);
}
void	malloc_map(t_fdf *fdf)
{
	int		i;
	t_map	*map;

	i = 0;
	map = fdf->map;
	if (map->height == 0 || map->width == 0)
	{
		exit_and_close(fdf);
	}
	map->z_index = (int **)malloc((map->height) * sizeof(int *));
	if (!map->z_index)
		exit_and_close(fdf);
	i = 0;
	while (i < map->height)
	{
		map->z_index[i] = (int *)malloc((map->width) * sizeof(int));
		if (!map->z_index[i])
		{
			free_z_index_i(fdf, i);
			exit_and_close(fdf);
		}
		i++;
	}
}

void	fill_map(t_map *map)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->z_index[i][j] = ft_atoi(map->map_formatted[f]);
			f++;
			j++;
		}
		i++;
	}
}

char	*replace_nl_w_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = ' ';
		}
		i++;
	}
	return (str);
}

char	*read_map(const char *map, t_fdf *fdf)
{
	int		fd;
	int		r;
	char	buffer[100001];
	char	*str;

	str = malloc(1);
	if (!str)
		exit_and_close(fdf);
	str[0] = '\0';
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_and_close(fdf);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, 100000);
		if (!r)
			break ;
		if (r == -1)
			exit_and_close(fdf);
		str = ft_strjoin(str, buffer);
	}
	close(fd);
	return (str);
}

void	find_highest_and_lowest(t_map *map)
{
	int	x;
	int	y;
	int	lowest;
	int	highest;

	x = 0;
	y = 0;
	lowest = INT_MAX;
	highest = INT_MIN;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->z_index[x][y] > highest)
				highest = map->z_index[x][y];
			if (map->z_index[x][y] < lowest)
				lowest = map->z_index[x][y];
			y++;
		}
		x++;
	}
	map->highest = highest;
	map->lowest = lowest;
}


void	get_map(const char *argv[], t_fdf *fdf)
{
	fdf->map->map = read_map(argv[1], fdf);
	if (!fdf->map->map)
		exit_and_close(fdf);
	fdf->map->height = get_map_height(fdf->map->map);
	fdf->map->width = get_map_width(fdf->map->map);
	printf("width %d, height %d\n", fdf->map->width, fdf->map->height);
	fdf->map->map = replace_nl_w_space(fdf->map->map);
	fdf->map->del_count = count_delimiter(fdf->map->map, ' ');
	fdf->map->map_formatted = ft_split(fdf->map->map, ' ');
	if (!fdf->map->map_formatted)
		exit_and_close(fdf);
	malloc_map(fdf);
	fill_map(fdf->map);
	find_highest_and_lowest(fdf->map);
	printf("HIGHEST: %d, LOWEST: %d", fdf->map->highest, fdf->map->lowest);
}
