/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:59:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:27:25 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t size)
{
	size_t			i;
	unsigned char	temp;
	unsigned char	*saf_a;
	unsigned char	*saf_b;

	saf_a = (unsigned char*)a;
	saf_b = (unsigned char*)b;
	i = 0;
	while (i < size)
	{
		temp = saf_a[i];
		saf_a[i] = saf_b[i];
		saf_b[i] = temp;
		i++;
	}
}
