/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:15:25 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/12 15:13:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*prev;
	t_list	*curr;

	if (!lst || !f)
		return (NULL);
	res = (*f)(lst);
	if (!res)
		return (NULL);
	prev = res;
	lst = lst->next;
	while (lst)
	{
		curr = (*f)(lst);
		if (!curr)
			return (NULL);
		prev->next = curr;
		prev = curr;
		lst = lst->next;
	}
	return (res);
}
