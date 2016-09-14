/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:34:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/09 16:53:42 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cell;

	cell = (t_list *)malloc(sizeof(t_list));
	if (!cell)
		return (0);
	if (content == NULL)
		cell->content = NULL;
	else
		cell->content = ft_memdup(content, content_size);
	if (!cell->content)
		content_size = 0;
	cell->content_size = content_size;
	cell->next = 0;
	return (cell);
}
