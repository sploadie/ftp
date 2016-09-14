/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:34:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 16:54:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*neolst;
	t_list	*neobeg;
	t_list	*next;

	if (!lst)
		return (NULL);
	neolst = (t_list *)malloc(sizeof(t_list));
	if (!neolst)
		return (NULL);
	neobeg = neolst;
	next = lst->next;
	*neolst = *(f(lst));
	lst = next;
	while (lst != NULL)
	{
		neolst->next = (t_list *)malloc(sizeof(t_list));
		neolst = neolst->next;
		if (!neolst)
			return (NULL);
		next = lst->next;
		*neolst = *(f(lst));
		lst = next;
	}
	return (neobeg);
}
