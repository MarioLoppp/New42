/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:06:37 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/23 19:22:06 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*re_list;
	t_list	*tmp_nod;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	re_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp_nod = ft_lstnew(content);
		if (!tmp_nod)
		{
			del(content);
			ft_lstclear(&re_list, del);
			return (NULL);
		}
		ft_lstadd_back(&re_list, tmp_nod);
		lst = lst->next;
	}
	return (re_list);
}
