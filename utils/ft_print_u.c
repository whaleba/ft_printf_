/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:03:32 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_itoa_u(unsigned int n)
{
	int				i;
	char			*str;
	unsigned int	hold_n;

	i = 0;
	hold_n = n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = hold_n % 10 + '0';
		hold_n = hold_n / 10;
		i--;
	}
	return (str);
}

static char	*ft_make_str_ar(t_str *li, unsigned int u_int_arg)
{
	int		len;
	char	*str_ar;

	len = 0;
	if (li->accur == 0 && li->dot == 1 && u_int_arg == 0) /////////////////////
		str_ar = ft_zero_accur_and_zero_int();////////////////////////
	else
	{
		if (!(str_ar = ft_itoa_u(u_int_arg)))
			return (NULL);
		len = (int)ft_strlen(str_ar);
		if (li->accur > len)
			str_ar = ft_accur_zero(str_ar, li->accur - len);
	}
	return (str_ar);
}

static int	ft_print_u(char *str_ar, t_str *li)
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

int			ft_get_u(t_str *li, va_list vlist)
{
	char			*str_ar;
	int				check_err;
	unsigned int	u_int_arg;
	int				len;

	check_err = 0;
	len = 0;
	u_int_arg = va_arg(vlist, unsigned int);
	if (!(str_ar = ft_make_str_ar(li, u_int_arg)))
		return (-1);
	len = (int)ft_strlen(str_ar);
	li->result = li->result + len;
	if (li->width > len)
	{
		li->width = li->width - len;
		check_err = (ft_print_u(str_ar, li) == -1) ? -1 : 0;
	}
	else
		ft_putstr_fd(str_ar, 1);
	free(str_ar);
	str_ar = NULL;
	return (check_err);
}
