/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:39:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/20 09:35:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	unsigned char	**saf_ap;

	if (!ap || !*ap)
		return ;
	saf_ap = (unsigned char**)ap;
	free(*saf_ap);
	*saf_ap = NULL;
}
