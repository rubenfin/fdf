/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/31 17:25:31 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 10:20:19 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_transform(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(0.8 * fdf->map->data->angle_cos);
	*y = (*x + *y) * sin(0.8 + fdf->map->data->angle_y) - (z
			+ fdf->map->data->angle_z);
}

void	make_iso(float *x, float *y, int z, t_fdf *fdf)
{
	if (fdf->map->data->iso)
		iso_transform(x, y, z, fdf);
}

int	max_f(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	mod(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	bresenham(t_point *point, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	get_z_index(&z, &z1, point, fdf);
	move_z(&z, &z1, fdf);
	map_zoom(point, fdf);
	make_iso(&point->x, &point->y, z, fdf);
	make_iso(&point->x1, &point->y1, z1, fdf);
	calculate_pos(point, fdf);
	x_step = point->x1 - point->x;
	y_step = point->y1 - point->y;
	max = max_f(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(point->x - point->x1) || (int)(point->y - point->y1))
	{
		if (point->x > 0 && point->x < WIDTH && point->y > 0
			&& point->y < HEIGHT)
			mlx_put_pixel(fdf->image, point->x, point->y, get_color(z));
		point->x += x_step;
		point->y += y_step;
	}
}
