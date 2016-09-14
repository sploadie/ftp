/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/20 11:34:17 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitc(int n)
{
	int		count;
	long	tens;

	count = 1;
	tens = 10;
	if (n < 0)
		n = n * -1;
	while (n >= tens)
	{
		tens = tens * 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*ntxt;
	int		charnum;
	int		lastnum;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	charnum = ft_digitc(n);
	lastnum = 0;
	if (n < 0)
	{
		n = n * -1;
		charnum++;
		lastnum++;
		ntxt = ft_strnew(charnum);
		ntxt[0] = '-';
	}
	else
		ntxt = ft_strnew(charnum);
	charnum--;
	while (charnum >= lastnum)
	{
		ntxt[charnum--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ntxt);
}
