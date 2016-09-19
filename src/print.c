/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 13:36:48 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/19 13:08:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	pexit(char *str, int outno)
{
	write(2, str, ft_strlen(str));
	exit(outno);
}

int		perr(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
