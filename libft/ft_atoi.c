/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:29:55 by harmida           #+#    #+#             */
/*   Updated: 2020/05/25 23:23:54 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_test_j(int j, int minus)
{
	if (j > 18 && minus == -1)
		return (0); 
	if (j >= 19)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	number;
	int			minus;
	int			i;
	int			j;

	number = 0;
	minus = 1;
	i = 0;
	j = 0;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		if (j != 0 || (j == 0 && str[i] != '0'))
			j++;
		i++;
	}
	return ((ft_test_j(j, minus) == 1) ? ((int)(number * minus)) : ft_test_j(j, minus));
}
