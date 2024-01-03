/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 10:20:59 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/03 14:17:36 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	i;

	if (!s || ft_strlen((char *)s) == 0)
		return (0);
	temp = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!temp)
		return (0);
	i = 0;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*full_s;
	int		i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	full_s = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!full_s)
	{
		free(s1);
		return (0);
	}
	i = 0;
	while (s1[i])
	{
		full_s[i] = s1[i];
		i++;
	}
	while (*s2)
		full_s[i++] = *(s2++);
	full_s[i] = '\0';
	free(s1);
	return (full_s);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		x;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (*big && i < len)
	{
		x = 0;
		while (*big == *little && i < len)
		{
			x++;
			little++;
			big++;
			if (*little == '\0' && !*big)
				return ((char *)big - x);
			i++;
		}
		i -= x;
		little -= x;
		big -= x;
		big++;
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*make_str(t_fdf *fdf)
{
	char	*str;

	str = malloc(1);
	if (!str)
		free_and_exit(fdf);
	str[0] = '\0';
	return (str);
}
