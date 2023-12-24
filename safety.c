/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safety.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 18:02:42 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/24 13:06:06 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	exit_and_close(t_fdf *fdf)
{
	free_all(fdf);
	perror("error with map");
	exit(EXIT_FAILURE);
}

void	free_z_index(t_fdf *fdf)
{
	int	y;

	y = 0;
	if (!fdf->map->height)
		return ;
	while (y < fdf->map->height)
	{
		free(fdf->map->z_index[y]);
		fdf->map->z_index[y] = 0;
		y++;
	}
	free(fdf->map->z_index);
	fdf->map->z_index = 0;
}

void	free_z_index_i(t_fdf *fdf, int i)
{
	while (i > 0)
	{
		free(fdf->map->z_index[i]);
		fdf->map->z_index[i] = 0;
		i--;
	}
	free(fdf->map->z_index);
	fdf->map->z_index = 0;
}

void	free_map_formatted(t_fdf *fdf)
{
	int	y;

	y = 0;
	while (y < fdf->map->del_count)
	{
		free(fdf->map->map_formatted[y]);
		fdf->map->map_formatted[y] = 0;
		y++;
	}
	free(fdf->map->map_formatted);
	fdf->map->map_formatted = 0;
}

int	free_all(t_fdf *fdf)
{
	if (fdf->map->z_index)
		free_z_index(fdf);
	if (fdf->map->map_formatted)
		free_map_formatted(fdf);
	if (fdf->map->map)
		free(fdf->map->map);
	if (fdf->map->data)
		free(fdf->map->data);
	if (fdf->map)
		free(fdf->map);
	if (fdf)
		free(fdf);
	return (0);
}
