/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:10:12 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_persent_with_arg(t_str *li)
{
	if (li->width > 0)
		li->width--;
	li->result = li->result + li->width + 1;
	if ((li->minus == 1 && li->zero == 1) || li->minus == 1)
	{
		write(1, "%", 1);
		if (ft_print_width(li, ' ') == -1)
			return (-1);
	}
	else if (li->zero == 1 && li->dot == 0)
	{
		if (ft_print_width(li, '0') == -1)
			return (-1);
		write(1, "%", 1);
	}
	else
	{
		if (ft_print_width(li, ' ') == -1)
			return (-1);
		write(1, "%", 1);
	}
	ft_change_zero_list(li, 1);
	return (0);
}

static void	ft_print_percent(t_str *li)
{
	if (li->percent == 2)
	{
		write(1, "%", 1);
		li->result++;
		li->percent = 0;
	}
}

static int	ft_check_double_percent(const char *format, t_str *li)
{
	int	i;

	i = 0;
	if (li->percent == 1 && format[i] == '%')
	{
		if (ft_print_persent_with_arg(li) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int			ft_scan(const char *format, t_str *li)
{
	int	i;
	int	start_print;

	i = 0;
	start_print = 0;
	if ((i = ft_check_double_percent(format, li)) == -1)
		return (-1);
	start_print = i;
	while (format[i] != '\0' && li->percent != 1)
	{
		if (format[i] == '%')
			ft_putstr_n((char *)&format[start_print], i - start_print, li);
		while (format[i] == '%')
		{
			li->percent++;
			ft_print_percent(li);
			i++;
			start_print = (li->percent == 1 && format[i] != '\0') ? i + 1: i;
		}
		if (format[i] != '\0' && li->percent != 1)
			i++;
	}
	if (format[i] == '\0')
		ft_putstr_n((char *)&format[start_print], i - start_print, li);
	return (i);
}
