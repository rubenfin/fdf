/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 11:24:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/22 15:55:38 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fdf = (t_fdf *)param;
	if (ydelta > 0)
	{
		fdf->map->map_zoom *= 1.05;
	}
	else if (ydelta < 0)
	{
		fdf->map->map_zoom *= 0.98;
	}
	draw_map(fdf);
}
void	ft_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_Q))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_W))
		fdf->map->pixel_pos_y -= 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_S))
		fdf->map->pixel_pos_y += 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_A))
		fdf->map->pixel_pos_x -= 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_D))
		fdf->map->pixel_pos_x += 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
	{
		fdf->map->data->x += 0.05;
		// fdf->map->data->z += 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_F))
	{
		fdf->map->data->x -= 0.05;
		// fdf->map->data->z -= 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
	{
		fdf->map->data->y += 0.1;
		fdf->map->data->z += 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
	{
		fdf->map->data->y -= 0.1;
		fdf->map->data->z -= 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
	{
		fdf->map->map_zoom = 5;
		fdf->map->pixel_pos_x = 900;
		fdf->map->pixel_pos_y = 550;
		fdf->map->data->x = 0;
		fdf->map->data->y = 0;
		fdf->map->data->x1 = 0;
		fdf->map->data->y1 = 0;
		fdf->map->data->z = 0;
		fdf->map->data->z1 = 0;
		fdf->map->data->iso = 1;
		fdf->map->data->move_z1 = 1;
		fdf->map->data->move_z = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		if (fdf->map->data->iso == 1)
		{
			fdf->map->data->iso = 0;
			fdf->map->pixel_pos_x = 500;
			fdf->map->pixel_pos_y = 250;
		}
		else
		{
			fdf->map->data->iso = 1;
			fdf->map->pixel_pos_x = 900;
			fdf->map->pixel_pos_y = 550;
		}
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_T))
	{
		fdf->map->data->move_z1 += 0.05;
		fdf->map->data->move_z += 0.05;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_G))
	{
		fdf->map->data->move_z1 -= 0.05;
		fdf->map->data->move_z -= 0.05;
	}
	draw_map(fdf);
}
