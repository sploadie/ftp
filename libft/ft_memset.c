/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:54:38 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/14 17:15:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*saf_b;

	if (!b)
		return (NULL);
	saf_b = b;
	while (len-- > 0)
		*saf_b++ = (unsigned char)c;
	return (b);
}
