/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:32:44 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 11:54:21 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_map(t_fdf *fdf)
{
	int		i;
	t_map	*map;

	i = 0;
	map = fdf->map;
	if (map->height == 0 || map->width == 0)
	{
		print_error("map is empty");
		free_and_exit(fdf);
	}
	map->z_index = (int **)malloc((map->height) * sizeof(int *));
	if (!map->z_index)
		free_and_exit(fdf);
	i = 0;
	while (i < map->height)
	{
		map->z_index[i] = (int *)malloc((map->width) * sizeof(int));
		if (!map->z_index[i])
		{
			free_z_index_i(fdf, i);
			free_and_exit(fdf);
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
			str[i] = ' ';
		i++;
	}
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
