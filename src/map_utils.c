/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:10:28 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/11 11:40:30 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_prev_count(char *map, int *i)
{
	int	prev_count;

	prev_count = 0;
	*i = 0;
	while (map[*i] && map[*i] != '\n')
	{
		if (num_or_alph(map[*i]) && (map[*i + 1] == '\n' || (map[*i + 1] == ' '
					|| map[*i + 1] == '\0')))
			prev_count++;
		(*i)++;
	}
	return (prev_count);
}

int	check_for_same_width(int i, char *map, int prev_count, t_fdf *fdf)
{
	static int	count;

	if (map[i] == '\n')
	{
		if (count != prev_count)
			print_free_exit("use same width for every line", fdf);
		count = 0;
	}
	if (num_or_alph(map[i]) && (map[i + 1] == '\n' || (map[i + 1] == ' '
				|| map[i + 1] == '\0')))
		count++;
	return (count);
}
