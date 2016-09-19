/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 12:49:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/19 15:07:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static void		recv_to_file(t_sock_data *sock, size_t size, char *file_path)
{
	int		fd;
	char	buf[size];

	recv(sock->id, buf, size, MSG_WAITALL);
	if ((fd = open(file_path, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		return ((void)perr("Error: could not open local file\n"));
	write(fd, buf, size);
	close(fd);
}

void			client_get(t_sock_data *sock, t_ftp_cmd *cmd)
{
	size_t	size;

	recv(sock->id, &size, sizeof(size_t), 0);
	ft_putstr("File size is ");
	ft_putnbr(size);
	ft_putstr("\n");
	if (size > 0)
		recv_to_file(sock, size, cmd->ascii);
}

static size_t	file_size(int fd)
{
	struct stat	buf;
	int			ret;

	ret = fstat(fd, &buf);
	ft_putstr("File size is ");
	ft_putnbr(buf.st_size);
	ft_putstr("\n");
	if (ret == -1)
		return (0);
	return (buf.st_size);
}

static int		is_dir(char *name)
{
	int			fd;
	struct stat	buf;
	int			ret;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (0);
	ret = fstat(fd, &buf);
	close(fd);
	if (ret == -1)
		return (0);
	if (buf.st_mode & S_IFDIR)
		return (1);
	return (0);
}

void			client_put(t_sock_data *sock, t_ftp_cmd *cmd)
{
	int		fd;
	size_t	size;
	void	*buf;

	fd = 0;
	if (is_dir(cmd->ascii) || ((fd = open(cmd->ascii, O_RDONLY)) < 0))
	{
		size = perr("Error: could not open local file\n");
		send(sock->id, &size, sizeof(size_t), 0);
		return ;
	}
	size = file_size(fd);
	buf = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (buf == NULL)
		size = perr("Error: Could not allocate space for local file\n");
	send(sock->id, &size, sizeof(size_t), 0);
	if (size > 0)
		send(sock->id, buf, size, 0);
	munmap(buf, size);
	close(fd);
}
