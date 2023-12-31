/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 11:24:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/31 17:11:24 by rfinneru      ########   odam.nl         */
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
		fdf->map->map_zoom *= 1.05;
	else if (ydelta < 0)
		fdf->map->map_zoom *= 0.98;
	draw_map(fdf);
	xdelta = 0;
}
void	ft_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;		
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_1))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_W))
		fdf->map->data->pixel_pos_y -= 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_S))
		fdf->map->data->pixel_pos_y += 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_A))
		fdf->map->data->pixel_pos_x -= 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_D))
		fdf->map->data->pixel_pos_x += 10 + fdf->map->map_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		fdf->map->data->angle_cos += 0.04;
		// fdf->map->data->z += 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		fdf->map->data->angle_cos -= 0.04;
		// fdf->map->data->z -= 0.5;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
	{
		fdf->map->data->angle_y += 0.05;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
	{
		fdf->map->data->angle_y -= 0.05;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
	{
		fdf->map->map_zoom = 5;
		fdf->map->data->pixel_pos_x = 900;
		fdf->map->data->pixel_pos_y = 550;
		fdf->map->data->angle_cos = 0;
		fdf->map->data->angle_y = 0;
		fdf->map->data->iso = 1;
		fdf->map->data->move_z = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		if (fdf->map->data->iso == 1)
		{
			fdf->map->data->iso = 0;
			fdf->map->data->pixel_pos_x = 500;
			fdf->map->data->pixel_pos_y = 250;
		}
		else
		{
			fdf->map->data->iso = 1;
			fdf->map->data->pixel_pos_x = 900;
			fdf->map->data->pixel_pos_y = 550;
		}
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
	{
		fdf->map->data->move_z += 0.05;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
	{
		fdf->map->data->move_z -= 0.05;
	}
	draw_map(fdf);
}
