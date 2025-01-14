/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safety2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 11:12:47 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/11 11:23:52 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free(char **buffer)
{
	if (*buffer)
		free(*buffer);
	(*buffer = NULL);
}

void	ft_free_multi(char **buffer, char **buffer2)
{
	ft_free(buffer);
	if (buffer2)
		ft_free(buffer2);
}

void	ft_free_and_exit(char **buffer, t_fdf *fdf)
{
	ft_free(buffer);
	free_and_exit(fdf);
}

void	print_free_exit(char *msg, t_fdf *fdf)
{
	print_error(msg);
	free_all(fdf);
	exit(EXIT_FAILURE);
}
