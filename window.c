/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:49:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/22 10:30:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_string(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "MOVE-UP: W | UP-ARROW", WIDTH / 15, HEIGHT / 15);
	mlx_put_string(fdf->mlx, "MOVE-LEFT: A | LEFT-ARROW", WIDTH / 15, HEIGHT
		/ 12.5);
	mlx_put_string(fdf->mlx, "MOVE-RIGHT: D | RIGHT-ARROW", WIDTH / 15, HEIGHT
		/ 10.8);
	mlx_put_string(fdf->mlx, "MOVE-DOWN: S | DOWN-ARROW", WIDTH / 15, HEIGHT
		/ 9.5);
	mlx_put_string(fdf->mlx, "QUIT: ESC | Q", WIDTH / 15, HEIGHT / 8);
}

int	make_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF - Ruben Finnerud", true);
	if (!fdf->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->image)
	{
		mlx_close_window(fdf->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) == -1)
	{
		mlx_close_window(fdf->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	put_string(fdf);
	return (EXIT_SUCCESS);
}
