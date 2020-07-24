/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:37:25 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 19:57:58 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (n == 0)
		return (dest);
	if ((!dest && !source) || n == 0)
		return (dest);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return ((void *)dst);
}
