/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/18 16:43:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*neoscript;

	if (!s)
		return (NULL);
	neoscript = ft_strnew(len);
	if (!neoscript)
		return (NULL);
	ft_strncpy(neoscript, (char*)(s + start), len);
	return (neoscript);
}
