/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_zero_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 20:41:57 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_change_zero_list(t_str *li, int res)
{
	li->zero = 0;
	li->minus = 0;
	li->dot = 0;
	li->width = 0;
	li->accur = 0;
	li->percent = 0;
	li->shift = 0;
	li->star_accuracy = 0;
	if (res == 0)
	{
		li->result = 0;
	}
}
