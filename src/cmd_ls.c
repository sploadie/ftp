/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 10:38:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static int	is_dir(char *name)
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

static char	*ls_append(char *str, struct dirent *file)
{
	char	buf[MAXNAMLEN + 3];
	char	*tmp;

	ft_strcpy(buf, file->d_name);
	if (is_dir(file->d_name))
		ft_strcat(buf, "/");
	ft_strcat(buf, "\n");
	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

void		cmd_ls(t_sock_data *sock)
{
	char			*tmp;
	size_t			len;
	DIR				*dir;
	struct dirent	*file;

	tmp = ft_strnew(0);
	dir = opendir(get_dir());
	while ((file = readdir(dir)) != NULL)
		tmp = ls_append(tmp, file);
	closedir(dir);
	len = ft_strlen(tmp);
	send(sock->id, &len, sizeof(size_t), 0);
	send(sock->id, tmp, len, 0);
	free(tmp);
}
