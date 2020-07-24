/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:38:54 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 19:21:16 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0')
		{
			if (i < (size - 1))
				dst[i] = src[i];
			if (i == size - 1)
				dst[i] = '\0';
			i++;
		}
		if (len > size)
			dst[size - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (len);
}
