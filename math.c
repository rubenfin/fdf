/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/31 17:25:31 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/31 17:36:49 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = fdf->map->z_index[(int)y][(int)x];
	z1 = fdf->map->z_index[(int)y1][(int)x1];
	move_z(&z, &z1, fdf);
	map_zoom(&x, &y, &x1, &y1, fdf);
	if (fdf->map->data->iso)
	{
		iso_transform(&x, &y, z, fdf);
		iso_transform(&x1, &y1, z1, fdf);
	}
	calculate_pos(&x, &y, &x1, &y1, fdf);
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_f(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			mlx_put_pixel(fdf->image, x, y, get_color(z));
		x += x_step;
		y += y_step;
	}
}