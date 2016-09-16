/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 16:56:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 10:51:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	cmd_cd(t_sock_data *sock, char *ascii)
{
	int	ret;

	if (*ascii == 0)
		ret = chdir(get_root());
	else
		ret = chdir(ascii);
	if (ret == -1 || ft_strlen(get_dir()) < ft_strlen(get_root()))
		chdir(get_root());
	cmd_pwd(sock);
}
