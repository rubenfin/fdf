/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:34:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 10:28:29 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	init_point(int x, int y, t_point *point, int flag)
{
	if (flag)
	{
		point->x = x;
		point->y = y;
		point->x1 = x + 1;
		point->y1 = y;
	}
	else
	{
		point->x = x;
		point->y = y;
		point->x1 = x;
		point->y1 = y + 1;
	}
}

void	draw_map(void *param)
{
	int		y;
	int		x;
	t_fdf	*fdf;
	t_point	point;

	fdf = (t_fdf *)param;
	reset_map(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
			{
				init_point(x, y, &point, 1);
				bresenham(&point, fdf);
			}
			if (y < fdf->map->height - 1)
			{
				init_point(x, y, &point, 0);
				bresenham(&point, fdf);
			}
		}
	}
}
