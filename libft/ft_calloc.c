/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:31:08 by harmida           #+#    #+#             */
/*   Updated: 2020/05/20 23:56:54 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (!(str = malloc(count * size)))
		return (NULL);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
