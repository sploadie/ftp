/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:26:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	char	*end_dest;

	end_dest = dest + ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		end_dest[i] = src[i];
		i++;
	}
	end_dest[i] = '\0';
	return (dest);
}
