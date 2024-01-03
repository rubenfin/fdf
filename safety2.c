/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safety2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 11:12:47 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 11:41:24 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
