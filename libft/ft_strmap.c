/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:06:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/18 16:40:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*neoscript;

	if (!s || !f)
		return (NULL);
	neoscript = ft_strnew(ft_strlen((char*)s));
	if (!neoscript)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		neoscript[i] = f(s[i]);
		i++;
	}
	return (neoscript);
}
