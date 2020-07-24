/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:39:33 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_str
{
	int	zero;
	int	minus;
	int	star_accuracy;
	int	dot;
	int	shift;
	int	result;
	int	width;
	int	accur;
	int	percent;
}				t_str;

char			*ft_accur_zero(char *str, int num);
char			*ft_zero_accur_and_zero_int();
int				ft_get_p(t_str *li, va_list vlist);
int				ft_get_s(t_str *li, va_list vlist);
int				ft_get_u(t_str *li, va_list vlist);
int				ft_get_x(t_str *li, va_list vlist);
int				ft_scan(const char *format, t_str *li);
int				ft_get_d(t_str *li, va_list vlist);
int				ft_print_width(t_str *li, char ch);
int				ft_get_c(t_str *li, va_list vlist);
int				ft_what_a_char(const char *format, t_str *li, va_list vlist);
void			ft_change_zero_list(t_str *li, int res);
void			ft_putstr_n(char *s, int num, t_str *li);
int				ft_printf(const char *format, ...);

#endif