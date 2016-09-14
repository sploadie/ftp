/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 22:39:40 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/10 17:38:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	int		i;
	size_t	src_size;
	size_t	dst_size;
	int		fin_size;
	char	*end_dest;

	dst_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	fin_size = (int)size - (int)dst_size - 1;
	if (fin_size + 1 <= 0)
		return (src_size + size);
	end_dest = dest + dst_size;
	i = 0;
	while (i < fin_size && src[i])
	{
		end_dest[i] = src[i];
		i++;
	}
	end_dest[i] = '\0';
	return (src_size + dst_size);
}
