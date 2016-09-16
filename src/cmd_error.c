/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 11:29:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	cmd_error(t_sock_data *sock, char *ascii)
{
	char	buf[23];
	size_t	len;

	perr("Unknown Command: ");
	perr(ascii);
	perr("\n");
	ft_strcpy(buf, "Error: Unknown Command");
	len = ft_strlen(buf);
	send(sock->id, &len, sizeof(size_t), 0);
	send(sock->id, buf, len, 0);
}
