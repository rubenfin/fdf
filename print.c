/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:36:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/09 11:05:01 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_formatted(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		j++;
		while (j < map->width)
		{
			printf("%3d", map->z_index[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
