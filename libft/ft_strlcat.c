/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:38:48 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 17:31:54 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	res;

	i = 0;
	len = 0;
	res = (ft_strlen(dst) + ft_strlen(src));
	while (dst[len] != '\0')
		len++;
	if (size > len)
	{
		size = size - len - 1;
		while (size > 0 && src[i] != '\0')
		{
			dst[len] = src[i];
			size--;
			i++;
			len++;
		}
		dst[len] = '\0';
		return (res);
	}
	else
		return (size + ft_strlen(src));
}
