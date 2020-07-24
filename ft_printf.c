/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:08:57 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pre_atoi(const char *format, t_str *li, int i)
{
	if ((format[i] >= '0' && format[i] <= '9') || (li->dot == 1 && format[i] == '-'))
	{
		if (li->dot != 1 && format[i] >= '1' && format[i] <= '9')
			li->width = ft_atoi((char *)(&format[i]));
		if (li->dot == 1)
			li->accur = ft_atoi((char *)(&format[i]));
		if (li->width > 0 || li->dot == 1)
		{
			if (li->dot == 1 && format[i] == '-')
				i++;
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			//i--;
		}
	}
	return (i);
}

static void	ft_width_star(const char *format, t_str *li, va_list vlist, int i)
{
	int	varg_temp;

	varg_temp = 0;
	if (li->dot == 0 && format[i] == '*')
	{
		varg_temp = va_arg(vlist, int);
		if (varg_temp < 0)
		{
			li->width = varg_temp * -1;
			li->minus = 1;
			li->zero = 0;
		}
		else
			li->width = varg_temp;
		varg_temp = 0;
	}
}

static int	ft_searh_flags(const char *format, t_str *li, va_list vlist, int i)
{
	int	varg_temp;

	varg_temp = 0;
	if (format[i] == '-' && li->dot == 0)
		li->minus = 1;
	if (format[i] == '0' && li->dot == 0)
		li->zero = 1;
	i = ft_pre_atoi(format, li, i);
	ft_width_star(format, li, vlist, i);
	if (format[i] == '.')
		li->dot = 1;
	if (li->dot == 1 && format[i] == '*')
	{
		varg_temp = va_arg(vlist, int);
		if (varg_temp >= 0)
			li->accur = varg_temp;
		else
		{
			li->accur = 0;
			li->dot = 0;
		}
	}
	return (i);
}

static int	ft_begin(const char *format, t_str *li, va_list vlist, int check)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if ((check = ft_scan(&format[i], li)) == -1)
			return (-1);
		i = i + check;
		while (format[i] != '\0' && format[i] != '%')
		{
			i = ft_searh_flags(format, li, vlist, i);
			check = ft_what_a_char(&format[i], li, vlist);
			if (check == 0)
			{
				ft_change_zero_list(li, 1);
				break ;
			}
			if (check == -1)
				return (-1);
			i = (format[i] != '\0' && format[i] != '%') ? i + 1 : i;
		}
		i = (format[i] != '\0' && format[i] != '%') ? i + 1 : i;
	}
	return (li->result);
}

int			ft_printf(const char *format, ...)
{
	va_list	vlist;
	t_str	*li;
	int		i;
	int		check;

	i = 0;
	check = 0;
	va_start(vlist, format);
	if (!(li = malloc(sizeof(t_str))))
		return (-1);
	ft_change_zero_list(li, 0);
	i = ft_begin(format, li, vlist, check);
	free(li);
	li = NULL;
	va_end(vlist);
	return (i);
}
