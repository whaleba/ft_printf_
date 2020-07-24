/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:37:06 by harmida           #+#    #+#             */
/*   Updated: 2020/05/23 15:33:13 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_source;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_source = (unsigned char *)source;
	while (i < n)
	{
		str_dest[i] = str_source[i];
		if (str_dest[i] == (unsigned char)ch)
			return ((void *)str_dest + i + 1);
		i++;
	}
	return (NULL);
}
