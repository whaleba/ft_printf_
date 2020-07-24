/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:54:59 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_accur_zero_minus(char *str, int num)
{
	char	*new_str;
	int		i;
	int		len;

	i = 0;
	len = num + (int)ft_strlen(str) + 1;
	if (!(new_str = (char *)malloc(sizeof(char) * len)))
	{
		free(str);
		return (NULL);
	}
	new_str[i++] = '-';
	while (num > i)
	{
		new_str[i] = '0';
		i++;
	}
	while (str[i - num] != '\0')
	{
		new_str[i] = str[i + 1 - num];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

static char	*ft_pre_accur_zero(int int_arg, t_str *li)
{
	char	*str_ar;
	int		len;

	len = 0;
	if (li->accur == 0 && li->dot == 1 && int_arg == 0)
		str_ar = ft_zero_accur_and_zero_int();
	else
		str_ar = ft_itoa(int_arg);
	if (str_ar == NULL)
		return (NULL);
	len = (int)ft_strlen(str_ar);
	if (int_arg >= 0)
	{
		if (li->accur > len)
			str_ar = ft_accur_zero(str_ar, li->accur - len);
	}
	else
	{
		if (li->accur > len - 1)
			str_ar = ft_accur_zero_minus(str_ar, li->accur - len + 2);
		if (li->width > len && li->dot == 0 && li->zero == 1 && li->minus == 0)
			str_ar = ft_accur_zero_minus(str_ar, li->width - len + 1);
	}
	return (str_ar);
}

static int	ft_print_d(char *str_ar, t_str *li)
{
	li->result = li->result + li->width;
	if ((li->minus == 1 && li->zero == 1) || li->minus == 1)
	{
		ft_putstr_fd(str_ar, 1);
		if (ft_print_width(li, ' ') == -1)
			return (-1);
	}
	else if (li->zero == 1 && li->dot == 0)
	{
		if (ft_print_width(li, '0') == -1)
			return (-1);
		ft_putstr_fd(str_ar, 1);
	}
	else
	{
		if (ft_print_width(li, ' ') == -1)
			return (-1);
		ft_putstr_fd(str_ar, 1);
	}
	return (0);
}

int		ft_get_d(t_str *li, va_list vlist)
{
	char	*str_ar;
	int		check_err;
	int		int_arg;
	int		len;

	check_err = 0;
	len = 0;
	int_arg = va_arg(vlist, int);
	if (!(str_ar = ft_pre_accur_zero(int_arg, li)))
		return (-1);
	len = (int)ft_strlen(str_ar);
	li->result = li->result + len;
	if (li->width > len)
	{
		li->width = li->width - len;
		if (ft_print_d(str_ar, li) == -1)
			check_err = -1;
	}
	else
		ft_putstr_fd(str_ar, 1);
	free(str_ar);
	str_ar = NULL;
	return (check_err);
}
