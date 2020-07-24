/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_a_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:11:48 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_what_a_char(const char *format, t_str *li, va_list vlist)
{
	int	i;

	i = 0;
	if (format[i] == 'd' || format[i] == 'i')
		i = (ft_get_d(li, vlist) == -1) ? -1 : 0;
	else if (format[i] == 'c')
		i = (ft_get_c(li, vlist) == -1) ? -1 : 0;
	else if (format[i] == 's')
		i = (ft_get_s(li, vlist) == -1) ? -1 : 0;
	else if (format[i] == 'p')
		i = (ft_get_p(li, vlist) == -1) ? -1 : 0;
	else if (format[i] == 'u')
		i = (ft_get_u(li, vlist) == -1) ? -1 : 0;
	else if (format[i] == 'x' || format[i] == 'X')
	{
		if (format[i] == 'x')
			li->shift = 97;
		else
			li->shift = 65;
		i = (ft_get_x(li, vlist) == -1) ? -1 : 0;
	}
	else
		i = 1;
	return (i);
}
