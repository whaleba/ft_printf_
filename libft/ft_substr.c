/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:42:41 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 23:46:14 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len2;
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	if (len2 < start || len == 0)
		return (ft_strdup(""));
	if ((len2 - start) < len)
		len = len2 - start;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
