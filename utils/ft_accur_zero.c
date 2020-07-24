/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accur_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:33:36 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../ft_printf.h"

char		*ft_accur_zero(char *str, int num)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * (num + ft_strlen(str) + 1))))
	{
		free(str);
		return (NULL);
	}
	while (num > i)
	{
		new_str[i] = '0';
		i++;
	}
	while (str[i - num] != '\0')
	{
		new_str[i] = str[i - num];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}