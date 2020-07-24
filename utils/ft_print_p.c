/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:56:51 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_p_width(t_str *li, char ch)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (li->width + 2 + 1))))
		return (-1);
	if (ch == '0')
	{
		str[i++] = '0';
		str[i++] = 'x';
		li->width = li->width + 2;
	}
	while (li->width > i)
		str[i++] = ch;
	if (ch == ' ' && li->minus == 0)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	str[i] = '\0';
	write(1, str, i);
	free(str);
	str = NULL;
	return (0);
}

static int	ft_print_p(char *str_ar, t_str *li)
{
	li->width = li->width - ft_strlen(str_ar) - 2;
	li->result = li->result + li->width + 2;
	if ((li->minus == 1 && li->zero == 1) || li->minus == 1)
	{
		write(1, "0x", 2);
		ft_putstr_fd(str_ar, 1);
		if (ft_print_p_width(li, ' ') == -1)
			return (-1);
	}
	else if (li->zero == 1 && li->dot == 0)
	{
		if (ft_print_p_width(li, '0') == -1)
			return (-1);
		ft_putstr_fd(str_ar, 1);
	}
	else
	{
		if (ft_print_p_width(li, ' ') == -1)
			return (-1);
		ft_putstr_fd(str_ar, 1);
	}
	return (0);
}

static int	ft_count_itoa_p(size_t pntr)
{
	int	i;

	i = 0;
	if (pntr == 0)
		i++;
	while (pntr > 0)
	{
		pntr = pntr / 16;
		i++;
	}
	return (i);
}

static char	*ft_itoa_p(size_t pntr)
{
	size_t	temp;
	int		i;
	char	*str;

	i = 0;
	temp = 0;
	i = ft_count_itoa_p(pntr);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (pntr == 0)
		str[i] = '0';
	while (pntr > 0)
	{
		temp = pntr % 16;
		if (temp <= 9)
			str[i] = temp  + 48;
		else
			str[i] = temp + 97 - 10;
		pntr = pntr / 16;
		i--;
	}
	return (str);
}

int			ft_get_p(t_str *li, va_list vlist)
{
	char	*str_ar;
	int		check_err;
	size_t	pointer_arg;

	check_err = 0;
	pointer_arg = va_arg(vlist, size_t);
	if (!(str_ar = ft_itoa_p(pointer_arg)))
		return (-1);;
	if (li->accur == 0 && li->dot == 1 && pointer_arg == 0)
		str_ar = ft_zero_accur_and_zero_int();
	if (li->accur > (int)ft_strlen(str_ar))
		str_ar = ft_accur_zero(str_ar, li->accur - (int)ft_strlen(str_ar));
	if (str_ar == NULL)
		return (-1);
	li->result = li->result + (int)ft_strlen(str_ar);
	if (li->width > (int)ft_strlen(str_ar) + 2)
		check_err = (ft_print_p(str_ar, li) == -1) ? -1 : 0;
	else
	{
		ft_putstr_n((char *)"0x", 2, li);
		ft_putstr_fd(str_ar, 1);
	}
	free(str_ar);
	str_ar = NULL;
	return (check_err);
}