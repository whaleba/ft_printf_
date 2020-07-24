/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:38:42 by harmida           #+#    #+#             */
/*   Updated: 2020/05/24 23:15:54 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	i = 0;
	if (!s2 || !s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
