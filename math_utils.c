/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 10:26:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 10:26:44 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_zoom(t_point *point, t_fdf *fdf)
{
	point->x *= fdf->map->map_zoom;
	point->y *= fdf->map->map_zoom;
	point->x1 *= fdf->map->map_zoom;
	point->y1 *= fdf->map->map_zoom;
}

void	calculate_pos(t_point *point, t_fdf *fdf)
{
	point->x += fdf->map->data->pixel_pos_x;
	point->y += fdf->map->data->pixel_pos_y;
	point->x1 += fdf->map->data->pixel_pos_x;
	point->y1 += fdf->map->data->pixel_pos_y;
}

void	move_z(int *z, int *z1, t_fdf *fdf)
{
	*z *= fdf->map->data->move_z;
	*z1 *= fdf->map->data->move_z;
}

void	get_z_index(int *z, int *z1, t_point *point, t_fdf *fdf)
{
	*z = fdf->map->z_index[(int)point->y][(int)point->x];
	*z1 = fdf->map->z_index[(int)point->y1][(int)point->x1];
}
