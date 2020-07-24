/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:42:30 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 01:51:50 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	ch;

	start = 0;
	ch = 0;
	while (set[ch] != '\0')
	{
		if (s1[start] == set[ch])
		{
			start++;
			ch = 0;
		}
		else
			ch++;
	}
	return (start);
}

static size_t	f_end(char const *s1, char const *set, size_t len)
{
	size_t	end;
	size_t	ch;

	ch = 0;
	end = len - 1;
	while (set[ch] != '\0')
	{
		if (s1[end] == set[ch])
		{
			end--;
			ch = 0;
		}
		else
			ch++;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	ch;
	char	*str;

	ch = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (ft_strlen(set) == 0 || len == 0)
		return (str = ft_strdup(s1));
	start = f_start(s1, set);
	if (start == len)
		return (str = ft_strdup(""));
	end = f_end(s1, set, len);
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end)
	{
		str[ch++] = s1[start++];
	}
	str[ch] = '\0';
	return (str);
}
