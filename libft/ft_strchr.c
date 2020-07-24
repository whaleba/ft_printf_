/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:38:29 by harmida           #+#    #+#             */
/*   Updated: 2020/05/21 00:06:36 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}
