/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:34:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/31 17:26:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_plus(int z)
{
	if (z > 100)
		return (COLOR_TEN);
	else if (z > 11)
		return (COLOR_NINE);
	else if (z > 10)
		return (COLOR_EIGHT);
	else if (z > 9)
		return (COLOR_SEVEN);
	else if (z > 8)
		return (COLOR_SIX);
	else if (z > 7)
		return (COLOR_FIVE);
	else if (z > 5)
		return (COLOR_FOUR);
	else if (z > 3)
		return (COLOR_THREE);
	else if (z > 2)
		return (COLOR_TWO);
	else if (z > 0)
		return (COLOR_ONE);
	return (0xFFFFFFFF);
}

int	color_minus(int z)
{
	if (z >= -1)
		return (COLOR_MINONE);
	else if (z > -2)
		return (COLOR_MINTWO);
	else if (z > -3)
		return (COLOR_MINTHREE);
	else if (z > -5)
		return (COLOR_MINFOUR);
	else if (z > -7)
		return (COLOR_MINFIVE);
	else if (z > -8)
		return (COLOR_MINSIX);
	else if (z > -9)
		return (COLOR_MINSEVEN);
	else if (z > -10)
		return (COLOR_MINEIGHT);
	else if (z > -11)
		return (COLOR_MINNINE);
	else if (z <= -12)
		return (COLOR_MINTEN);
	return (0xFFFFFFFF);
}

int	get_color(int z)
{
	if (z > 0)
		return (color_plus(z));
	else if (z < 0)
		return (color_minus(z));
	return (0xFFFFFFFF);
}


void	iso_transform(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(0.8 * fdf->map->data->angle_cos);
	*y = (*x + *y) * sin(0.8 + fdf->map->data->angle_y) - (z
			+ fdf->map->data->angle_z);
}

void	map_zoom(float *x, float *y, float *x1, float *y1, t_fdf *fdf)
{
	*x *= fdf->map->map_zoom;
	*y *= fdf->map->map_zoom;
	*x1 *= fdf->map->map_zoom;
	*y1 *= fdf->map->map_zoom;
}

void	calculate_pos(float *x, float *y, float *x1, float *y1, t_fdf *fdf)
{
	*x += fdf->map->data->pixel_pos_x;
	*y += fdf->map->data->pixel_pos_y;
	*x1 += fdf->map->data->pixel_pos_x;
	*y1 += fdf->map->data->pixel_pos_y;
}

void	move_z(int *z, int *z1, t_fdf *fdf)
{
	*z *= fdf->map->data->move_z;
	*z1 *= fdf->map->data->move_z;
}

void	reset_map(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(fdf->image, x, y, BACKGROUND_COLOR);
			x++;
		}
		y++;
	}
}

void	draw_map(void *param)
{
	int		y;
	int		x;
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	reset_map(fdf);
	x = 0;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(x, y, x + 1, y, fdf);
			if (y < fdf->map->height - 1)
				bresenham(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
}
