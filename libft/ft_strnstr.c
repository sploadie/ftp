/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:20:19 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:25:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;

	if (to_find[0] == '\0')
		return (str);
	if (str == '\0' || n < 1)
		return (NULL);
	i = 0;
	while (i < n && to_find[i] == str[i] && str[i] != '\0')
	{
		i++;
		if (to_find[i] == '\0')
			return (str);
	}
	if (str[i] == '\0' || i == n)
		return (NULL);
	return (ft_strnstr(str + 1, to_find, n - 1));
}
