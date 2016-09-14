/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:27:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	txtspc[11];
	char	*ntxt;

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	ntxt = &txtspc[10];
	*ntxt = '\0';
	if (n < 0 && (n *= -1))
		ft_putchar_fd('-', fd);
	while (n > 0)
	{
		*(--ntxt) = 48 + (n % 10);
		n = n / 10;
	}
	ft_putstr_fd(ntxt, fd);
}
