/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_accur_and_zero_int.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:46:32 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_zero_accur_and_zero_int()
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}