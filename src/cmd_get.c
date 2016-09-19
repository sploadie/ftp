/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/19 15:07:45 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static size_t	file_size(int fd)
{
	struct stat	buf;
	int			ret;

	ret = fstat(fd, &buf);
	if (ret == -1)
		return (0);
	ft_putstr("File size is ");
	ft_putnbr(buf.st_size);
	ft_putstr("\n");
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

void			cmd_get(t_sock_data *sock, char *ascii)
{
	int		fd;
	size_t	size;
	void	*buf;

	fd = 0;
	if (is_dir(ascii) || ((fd = open(basename(ascii), O_RDONLY)) < 0))
		perr("Error: Could not open server file\n");
	size = file_size(fd);
	buf = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (buf == NULL)
		size = perr("Error: Could not allocate space for server file\n");
	send(sock->id, &size, sizeof(size_t), 0);
	if (size > 0)
		send(sock->id, buf, size, 0);
	munmap(buf, size);
	if (size > 0)
		buf = ft_strdup("Server file sent\n");
	else
		buf = ft_strdup("Server file not sent\n");
	size = ft_strlen(buf);
	send(sock->id, &size, sizeof(size_t), 0);
	send(sock->id, buf, size, 0);
	free(buf);
	close(fd);
}
