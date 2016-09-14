/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/18 16:47:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_istrim(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	size;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	size = ft_strlen((char*)s);
	start = 0;
	while (ft_istrim(s[start]))
		start++;
	end = size;
	while (end > start && ft_istrim(s[end - 1]))
		end--;
	return (ft_strsub((char*)s, start, end - start));
}
