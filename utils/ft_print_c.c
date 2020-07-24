/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:44:30 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_c(unsigned char ch_arg, t_str *li)
{
	li->result = li->result + li->width;
	if (li->minus == 1)
	{
		write(1, &ch_arg, 1);
		if (ft_print_width(li, ' ') == -1)
			return (-1);
	}
	else
	{
		if (ft_print_width(li, ' ') == -1)
			return (-1);
		write(1, &ch_arg, 1);
	}
	return (0);
}

int	ft_get_c(t_str *li, va_list vlist)
{
	unsigned char	ch_arg;

	ch_arg = (unsigned char)va_arg(vlist, int);
	li->result = li->result + 1;
	if (li->width > 1)
	{
		li->width = li->width - 1;
		if (ft_print_c(ch_arg, li) == -1)
			return (-1);
	}
	else
		write(1, &ch_arg, 1);
	return (0); 
}
