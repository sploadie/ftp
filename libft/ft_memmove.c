/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/20 09:37:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	neo_src[n];
	unsigned char	*saf_dst;
	unsigned char	*saf_src;

	if (!dst || !src)
		return (NULL);
	saf_dst = (unsigned char*)dst;
	saf_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		neo_src[i] = saf_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		saf_dst[i] = neo_src[i];
		i++;
	}
	return (dst);
}
