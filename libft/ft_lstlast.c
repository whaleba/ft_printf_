/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:36:44 by harmida           #+#    #+#             */
/*   Updated: 2020/05/22 02:27:24 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*l_temp;

	l_temp = lst;
	if (lst == NULL)
		return (lst);
	while (l_temp->next != NULL)
		l_temp = l_temp->next;
	return (l_temp);
}
