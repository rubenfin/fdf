/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 11:24:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/10 13:36:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (ydelta > 0)
		fdf->map->map_zoom *= 1.02;
	else if (ydelta < 0)
		fdf->map->map_zoom *= 0.98;
	(void)xdelta;
}

void	ft_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	move_keys(fdf);
	move_angle(fdf);
	move_iso(fdf);
	move_z_index(fdf);
	draw_map(fdf);
}
