/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 11:24:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/22 12:31:44 by rfinneru      ########   odam.nl         */
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
		fdf->map->data->z *= 1.1;
		fdf->map->data->z1 *= 1.1;
	}
	else if (ydelta < 0)
	{
		fdf->map->data->z /= 1.1;
		fdf->map->data->z1 /= 1.1;
	}
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
		fdf->image->instances[0].y -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_S))
		fdf->image->instances[0].y += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_A))
		fdf->image->instances[0].x -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(fdf->mlx,
			MLX_KEY_D))
		fdf->image->instances[0].x += 10;
}
