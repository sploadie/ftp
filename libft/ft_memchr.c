/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:54:38 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/14 17:32:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		char_c;
	const unsigned char	*saf_s;

	if (!s)
		return (NULL);
	if (n < 1)
		return (0);
	saf_s = s;
	char_c = (unsigned char)c;
	while (n-- > 0)
	{
		if (*saf_s == char_c)
			return ((unsigned char*)saf_s);
		saf_s++;
	}
	return (0);
}
