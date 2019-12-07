/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:33:24 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/25 13:41:19 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*done;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	done = NULL;
	while (lst != NULL)
	{
		if ((tmp = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&done, del);
			return (NULL);
		}
		ft_lstadd_back(&done, tmp);
		lst = lst->next;
	}
	return (done);
}
