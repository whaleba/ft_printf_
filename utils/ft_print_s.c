/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:00:01 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_manipulate_accuracy_s(t_str *li)
{
	int	check_err;

	check_err = 0;
	if (li->accur < 0 && li->star_accuracy == 0)
	{
		li->width = li->accur * -1;
		check_err = (ft_print_width(li, ' ') == -1) ? -1 : 0;
	}
	if (li->accur < 0 && li->star_accuracy == 1)
	{
		li->accur = 0;
		li->dot = 0;
	}
	return (check_err);
}

static int	ft_print_s(char *str_ar, t_str *li, int check_err)
{
	char	ch_width; ////////��������� ����� �� 0 � ������ !!!!!!!!!!!!!

	if (li->dot == 0 || li->accur >= (int)ft_strlen(str_ar))
		li->accur = (int)ft_strlen(str_ar);
	if (li->width > li->accur && li->accur >= 0)
	{
		li->width = li->width - li->accur;
		li->result = li->result + li->width;
		if (li->minus == 0)
		{
			ch_width = (li->zero == 1) ? '0' : ' ';
			check_err = (ft_print_width(li, ch_width) == -1 || check_err == -1) ? -1 : 0;
			ft_putstr_n(str_ar, li->accur, li);
		}
		if (li->minus == 1)
		{
			ft_putstr_n(str_ar, li->accur, li);
			check_err = (ft_print_width(li, ' ') == -1 || check_err == -1) ? -1 : 0;
		}
	}
	else
		ft_putstr_n(str_ar, li->accur, li);
	return (check_err);
}

int			ft_get_s(t_str *li, va_list vlist)
{
	char	*str_ar;
	int		check_err;

	check_err = 0;
	str_ar = va_arg(vlist, char *);
	if (li->accur < 0 && li->star_accuracy == 0 && str_ar != NULL)
	{
		if (!(str_ar = ft_strdup("")))
			return (-1);
	}
	check_err = ft_manipulate_accuracy_s(li);
	if (str_ar == NULL)
	{
		if (!(str_ar = ft_strdup("(null)")))
			return (-1);
	}
	else
	{
		if (!(str_ar = ft_strdup(str_ar)))
			return (-1);
	}
	check_err = (check_err == -1 || (ft_print_s(str_ar, li, check_err) == -1)) ? -1 : 0;
	free(str_ar);
	str_ar = NULL;
	return (check_err);
}
