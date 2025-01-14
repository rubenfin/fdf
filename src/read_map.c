/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:15:05 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/11 11:41:54 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_fdf_file(const char *str, t_fdf *fdf)
{
	char	*type;
	int		i;
	int		x;
	int		end;

	type = ft_strdup("fdf.");
	if (!type)
		free_and_exit(fdf);
	i = ft_strlen((char *)str) - 1;
	end = ft_strlen((char *)str) - 5;
	x = 0;
	while (i > end)
	{
		if (str[i] != type[x])
		{
			free(type);
			print_error("only use .fdf files");
			free_all(fdf);
			exit(EXIT_FAILURE);
		}
		x++;
		i--;
	}
	free(type);
}

int	get_map_height(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	if (count == 0 && (map[0] >= '0' && map[0] <= '9'))
		return (1);
	return (count);
}

int	get_map_width(char *map, t_fdf *fdf)
{
	int	i;
	int	count;
	int	prev_count;

	i = 0;
	prev_count = get_prev_count(map, &i);
	if (map[i] == '\0')
		return (prev_count);
	i = 0;
	count = 0;
	while (map[i])
	{
		count = check_for_same_width(i, map, prev_count, fdf);
		i++;
	}
	if (count == prev_count)
		fdf->map->height++;
	else if (count)
		print_free_exit("use same width for every line", fdf);
	return (prev_count);
}

char	*read_map(const char *map, t_fdf *fdf)
{
	int		fd;
	int		r;
	char	buffer[100001];
	char	*str;

	str = make_str(fdf);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		print_error("error opening .fdf file");
		ft_free_and_exit(&str, fdf);
	}
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, 100000);
		if (r == -1)
			ft_free_and_exit(&str, fdf);
		buffer[r] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			ft_free_and_exit(&str, fdf);
	}
	close(fd);
	return (str);
}

void	get_map(const char *argv[], t_fdf *fdf)
{
	check_fdf_file(argv[1], fdf);
	fdf->map->map = read_map(argv[1], fdf);
	fdf->map->height = get_map_height(fdf->map->map);
	fdf->map->width = get_map_width(fdf->map->map, fdf);
	fdf->map->map = replace_nl_w_space(fdf->map->map);
	fdf->map->del_count = count_delimiter(fdf->map->map, ' ');
	fdf->map->map_formatted = ft_split(fdf->map->map, ' ');
	if (!fdf->map->map_formatted)
		free_and_exit(fdf);
	malloc_map(fdf);
	fill_map(fdf->map);
}
