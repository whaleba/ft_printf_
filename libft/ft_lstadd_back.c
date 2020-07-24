/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:32:34 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 01:00:11 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *l_temp;

	l_temp = *lst;
	if (!new || !lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		while (l_temp->next != NULL)
			l_temp = l_temp->next;
		l_temp->next = new;
	}
}
