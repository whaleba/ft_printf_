/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:41:52 by harmida           #+#    #+#             */
/*   Updated: 2020/07/23 21:09:53 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_n(char *s, int num, t_str *li)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && num > i)
			i++;
		write(1, s, i);
	}
	li->result = li->result + i;
}
