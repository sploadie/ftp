/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/15 12:37:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	cmd_pwd(t_sock_data *sock)
{
	char	str[MAXPATHLEN + 1];
	size_t	len;

	if (getcwd(str, MAXPATHLEN) == NULL)
	{
		ft_strcpy(str, "Error: getcwd failed");
	}
	else
	{
		ft_strcat(str, "/");
		ft_strcpy(str, str + ft_strlen(get_root()));
	}
	len = ft_strlen(str);
	send(sock->id, &len, sizeof(size_t), 0);
	send(sock->id, str, len, 0);
}
