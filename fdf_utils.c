/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:41:29 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/16 13:33:26 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ATOI
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

// MEMMOVE
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;

	if (!dest && !src)
		return (0);
	src_p = (const char *)src;
	dest_p = (char *)dest;
	if (dest_p > src_p && dest_p < src_p + n)
	{
		dest_p += n - 1;
		src_p += n - 1;
		while (n--)
		{
			*dest_p-- = *src_p--;
		}
	}
	else
	{
		while (n--)
		{
			*dest_p++ = *src_p++;
		}
	}
	return (dest);
}

// FT_SPLIT
static void	free_array(char **split_array, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		free(split_array[x]);
		x++;
	}
	free(split_array);
}

int	count_delimiter(char const *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (inside_word)
			{
				count++;
				inside_word = 0;
			}
		}
		else
		{
			if (!inside_word)
				inside_word = 1;
		}
		s++;
	}
	if (inside_word)
		count++;
	return (count);
}

static int	copy_word(char **split_arr, const char *start, int len, int i)
{
	int	j;

	j = 0;
	split_arr[i] = (char *)malloc(len + 1);
	if (!split_arr[i])
	{
		free_array(split_arr, i);
		return (0);
	}
	while (j < len)
	{
		split_arr[i][j] = start[j];
		j++;
	}
	split_arr[i][j] = '\0';
	return (1);
}

static int	put_words(char **split_arr, const char *s, char c)
{
	int			len;
	const char	*start;
	int			i;
	int			check;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			check = copy_word(split_arr, start, len, i);
			if (!check)
				return (0);
			i++;
		}
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	int		del_count;
	int		check;
	char	**split_arr;

	del_count = count_delimiter(s, c);
	split_arr = (char **)malloc((del_count + 1) * sizeof(char *));
	if (!split_arr)
		return (0);
	check = put_words(split_arr, s, c);
	if (!check)
		return (0);
	split_arr[del_count] = 0;
	return (split_arr);
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

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	i;

	if (!s)
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

	if (!s1)
		return (ft_strdup(s2));
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
	{
		free(s1);
		return (0);
	}
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

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int	num_or_alph(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}
