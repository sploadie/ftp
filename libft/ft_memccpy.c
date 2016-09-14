/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/14 17:34:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*saf_dst;
	const unsigned char	*saf_src;

	if (!dst || !src)
		return (NULL);
	saf_dst = dst;
	saf_src = src;
	i = 0;
	while (i < n)
	{
		if (saf_src[i] == (unsigned char)c)
		{
			saf_dst[i] = saf_src[i];
			return (saf_dst + i + 1);
		}
		saf_dst[i] = saf_src[i];
		i++;
	}
	return (0);
}
