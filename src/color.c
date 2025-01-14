/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:07:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 15:27:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	color_plus(int z)
{
	if (z > 100)
		return (COLOR_TEN);
	else if (z > 50)
		return (COLOR_NINE);
	else if (z > 25)
		return (COLOR_EIGHT);
	else if (z > 12)
		return (COLOR_SEVEN);
	else if (z > 9)
		return (COLOR_SIX);
	else if (z > 7)
		return (COLOR_FIVE);
	else if (z > 5)
		return (COLOR_FOUR);
	else if (z > 3)
		return (COLOR_THREE);
	else if (z >= 1)
		return (COLOR_TWO);
	else if (z > 0)
		return (COLOR_ONE);
	return (0xFFFFFFFF);
}

int	color_minus(int z)
{
	if (z >= -100)
		return (COLOR_MINNINE);
	else if (z >= -50)
		return (COLOR_MINEIGHT);
	else if (z >= -25)
		return (COLOR_MINSEVEN);
	else if (z >= -12)
		return (COLOR_MINSIX);
	else if (z >= -9)
		return (COLOR_MINFIVE);
	else if (z >= -7)
		return (COLOR_MINFOUR);
	else if (z >= -5)
		return (COLOR_MINTHREE);
	else if (z >= -3)
		return (COLOR_MINTWO);
	else if (z > 0)
		return (COLOR_MINONE);
	else
		return (COLOR_MINTEN);
}

int	get_color(int z)
{
	if (z > 0)
		return (color_plus(z));
	else if (z < 0)
		return (color_minus(z));
	return (0xFFFFFFFF);
}
