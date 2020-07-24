/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:42:15 by harmida           #+#    #+#             */
/*   Updated: 2020/05/21 00:10:25 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	start;

	b = 0;
	l = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > b && haystack[b] != '\0')
	{
		start = b;
		while (len > b && haystack[b] == needle[l] && haystack[b] != '\0')
		{
			b++;
			l++;
			if (needle[l] == '\0')
				return ((char *)haystack + start);
		}
		l = 0;
		b = start + 1;
	}
	return (NULL);
}
