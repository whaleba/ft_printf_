/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:44:35 by harmida           #+#    #+#             */
/*   Updated: 2020/05/26 16:20:56 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *toplist;
	t_list *newlist;

	if (f == NULL || lst == NULL || del == NULL)
		return (NULL);
	if (!(toplist = malloc(sizeof(t_list))))
		return (NULL);
	toplist->content = f(lst->content);
	toplist->next = NULL;
	lst = lst->next;
	while (lst)
	{
		if (!(newlist = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&toplist, del);
			return (NULL);
		}
		ft_lstadd_back(&toplist, newlist);
		lst = lst->next;
	}
	return (toplist);
}
