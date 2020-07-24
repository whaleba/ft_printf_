/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:37:34 by harmida           #+#    #+#             */
/*   Updated: 2020/05/26 22:53:41 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	i = 0;
	to = (unsigned char *)dest;
	from = (unsigned char *)source;
	if (dest == source || n == 0)
		return ((void *)dest);
	if (dest < source)
	{
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			to[n] = from[n];
		}
	}
	return ((void *)dest);
}
