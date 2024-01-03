/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 13:55:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 13:06:29 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	argc_check(int argc, t_fdf *fdf)
{
	if (argc == 2)
		return (1);
	else if (argc < 2)
		print_error("Not enough arguments: usage ./a.out map.fdf");
	else if (argc > 2)
		print_error("Too many arguments:  usage ./a.out map.fdf");
	free_all(fdf);
	exit(EXIT_FAILURE);
}

int	init_map_data(t_fdf *fdf)
{
	fdf->map->data = (t_data *)malloc(sizeof(t_data));
	if (!fdf->map->data)
		return (0);
	fdf->map->data->pixel_pos_x = 900;
	fdf->map->data->pixel_pos_y = 550;
	fdf->map->data->angle_cos = 0.0;
	fdf->map->data->angle_y = 0;
	fdf->map->data->angle_z = 0;
	fdf->map->data->move_z = 0;
	fdf->map->data->iso = 1;
	fdf->map->data->move_z = 1;
	return (1);
}

int	init_map(t_fdf *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		return (0);
	fdf->map->height = 0;
	fdf->map->width = 0;
	fdf->map->map = 0;
	fdf->map->map_formatted = 0;
	fdf->map->del_count = 0;
	fdf->map->map_zoom = 5;
	fdf->map->z_index = 0;
	fdf->map->data = 0;
	if (!init_map_data(fdf))
		return (0);
	return (1);
}

t_fdf	*init_fdf(t_fdf **fdf)
{
	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!*fdf)
		return (NULL);
	(*fdf)->map = 0;
	(*fdf)->mlx = 0;
	(*fdf)->image = 0;
	if (!init_map(*fdf))
	{
		free_all(*fdf);
		print_error("failure with initalizing fdf struct");
		return (NULL);
	}
	return (*fdf);
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_fdf	*fdf;

	if (!init_fdf(&fdf))
		exit(EXIT_FAILURE);
	if (argc_check(argc, fdf))
	{
		get_map(argv, fdf);
		if (make_window(fdf))
			free_and_exit(fdf);
		mlx_scroll_hook(fdf->mlx, &ft_scrollhook, fdf);
		mlx_loop_hook(fdf->mlx, &ft_hook, fdf);
		mlx_loop(fdf->mlx);
		mlx_terminate(fdf->mlx);
	}
	free_all(fdf);
	return (EXIT_SUCCESS);
}
