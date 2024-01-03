/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:41:29 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 11:02:37 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	sign_count(char num)
{
	int	sign;

	sign = 1;
	if (num == '-')
	{
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(char *nptr)
{
	int		value;
	int		sign;
	char	*num;
	int		i;

	i = 0;
	value = 0;
	sign = 1;
	num = (char *)nptr;
	while (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13))
	{
		i++;
	}
	if (num[i] == '-' || num[i] == '+')
	{
		sign = sign_count(num[i]);
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		value = value * 10 + (num[i] - '0');
		i++;
	}
	return (value * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

int	num_or_alph(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}

void	print_error(char *msg)
{
	if (errno)
		perror(msg);
	else
	{
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
	}
}
