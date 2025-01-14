/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:32:44 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/10 11:29:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
