/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:42:32 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/02 11:45:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_keys(t_fdf *fdf)
{
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
}

void	move_angle(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->map->data->angle_cos += 0.04;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		fdf->map->data->angle_cos -= 0.04;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		fdf->map->data->angle_y += 0.05;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->map->data->angle_y -= 0.05;
}

void	move_iso(t_fdf *fdf)
{
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
}

void	move_z_index(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
	{
		fdf->map->data->move_z += 0.05;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
	{
		fdf->map->data->move_z -= 0.05;
	}
}
