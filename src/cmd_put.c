/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 15:05:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static int	recv_to_file(t_sock_data *sock, size_t size, char *file_path)
{
	int		fd;
	char	buf[size];

	recv(sock->id, buf, size, MSG_WAITALL);
	if ((fd = open(file_path, O_CREAT | O_TRUNC | O_WRONLY)) < 0)
	{
		perr("Error: could not open server file\n");
		return (0);
	}
	write(fd, buf, size);
	close(fd);
	return (1);
}

void		cmd_put(t_sock_data *sock, char *ascii)
{
	size_t	size;
	char	*buf;
	int		ret;

	ret = 0;
	recv(sock->id, &size, sizeof(size_t), 0);
	ft_putstr("File size is ");
	ft_putnbr(size);
	ft_putstr("\n");
	if (size > 0)
		ret = recv_to_file(sock, size, basename(ascii));
	if (ret == 0)
		size = ft_strlen((buf = ft_strdup("Server did not save file\n")));
	else
		size = ft_strlen((buf = ft_strdup("Server saved file\n")));
	send(sock->id, &size, sizeof(size_t), 0);
	send(sock->id, buf, size, 0);
	free(buf);
}
