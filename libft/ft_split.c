/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:38:23 by harmida           #+#    #+#             */
/*   Updated: 2020/05/26 03:38:26 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f_free_mem(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int		f_string_count(char const *s, char c)
{
	int	char_count;
	int	str_count;

	char_count = 0;
	str_count = 0;
	while (s[char_count] != '\0')
	{
		if (char_count == 0)
		{
			if (s[char_count] != c)
				str_count++;
		}
		else
		{
			if (s[char_count] != c && s[char_count - 1] == c)
				str_count++;
		}
		char_count++;
	}
	return (str_count);
}

static int		f_make_array(char const *s, char **arr, char c, int str_count)
{
	int		i;
	size_t	j;
	size_t	char_count;

	i = 0;
	j = 0;
	while (i < str_count)
	{
		char_count = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			j++;
			char_count++;
		}
		arr[i] = ft_substr(s, (unsigned int)(j - char_count), char_count);
		if (arr[i] == NULL)
		{
			f_free_mem(arr, i - 1);
			return (0);
		}
		i++;
	}
	return (i);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		str_count;
	char	**arr;

	if (!s)
		return (NULL);
	str_count = f_string_count(s, c);
	if (str_count == 0)
	{
		if (!(arr = (char **)malloc(sizeof(char *))))
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	if (!(arr = (char **)malloc(sizeof(char *) * (str_count + 1))))
		return (NULL);
	i = f_make_array(s, arr, c, str_count);
	if (i == 0)
		return (NULL);
	arr[i] = NULL;
	return (arr);
}
