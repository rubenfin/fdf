/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 13:55:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/22 12:36:27 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	argc_check(int argc, t_fdf *fdf)
{
	if (argc == 2)
		return (1);
	else if (argc < 2)
		perror("Not enough arguments: usage ./a.out map.fdf \n");
	else if (argc > 2)
		perror("Too many arguments:  usage ./a.out map.fdf  \n");
	free_all(fdf);
	exit(EXIT_FAILURE);
	return (0);
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
	fdf->map->map_zoom = 0;
	fdf->map->pixel_pos_x = 0;
	fdf->map->z_index = 0;
	fdf->map->data = 0;
	fdf->map->data = (t_data *)malloc(sizeof(t_data));
	fdf->map->data->x = 0;
	fdf->map->data->y = 0;
	fdf->map->data->x1 = 0;
	fdf->map->data->y1 = 0;
	fdf->map->data->z = 0;
	fdf->map->data->z1 = 0;
	return (1);
}

t_fdf	*init_fdf(t_fdf **fdf)
{
	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	(*fdf)->map = 0;
	(*fdf)->mlx = 0;
	(*fdf)->image = 0;
	if (!*fdf)
		return (NULL);
	if (!init_map(*fdf))
	{
		free(*fdf);
		return (NULL);
	}
	return (*fdf);
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_fdf	*fdf;

	init_fdf(&fdf);
	if (!fdf)
		exit(EXIT_FAILURE);
	if (argc_check(argc, fdf))
	{
		get_map(argv, fdf);
		if (make_window(fdf) == 1)
		{
			free_all(fdf);
			return (EXIT_FAILURE);
		}
		draw_map(fdf);
		mlx_scroll_hook(fdf->mlx, &ft_scrollhook, fdf);
		mlx_loop_hook(fdf->mlx, &ft_hook, fdf);
		mlx_loop(fdf->mlx);
		mlx_terminate(fdf->mlx);
	}
	free_all(fdf);
	return (EXIT_SUCCESS);
}
