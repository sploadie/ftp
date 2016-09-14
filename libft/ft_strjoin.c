/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/18 16:43:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*neoscript;

	if (!s1 || !s2)
		return (NULL);
	neoscript = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!neoscript)
		return (NULL);
	ft_strcpy(neoscript, (char*)s1);
	ft_strcat(neoscript, (char*)s2);
	return (neoscript);
}
