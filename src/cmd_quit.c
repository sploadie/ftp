/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/15 13:33:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	cmd_quit(t_sock_data *sock)
{
	char	*str;
	size_t	len;

	str = ft_strdup("Server connection closed");
	len = ft_strlen(str);
	send(sock->id, &len, sizeof(size_t), 0);
	send(sock->id, str, len, 0);
	close(sock->id);
	pexit("Child closed\n", 0);
}
