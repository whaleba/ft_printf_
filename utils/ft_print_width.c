/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:05:30 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_width(t_str *li, char ch)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (li->width + 1))))
		return (-1);
	while (li->width > i)
		str[i++] = ch;
	str[i] = '\0';
	write(1, str, i);
	free(str);
	str = NULL;
	return (0);
}
