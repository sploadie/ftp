/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/14 19:39:41 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include "libft.h"

// # include <string.h>
// # include <stdio.h>
// # include <sys/sendfile.h>

# define BUF_SIZE 256
# define ASC_SIZE 256 - sizeof(uint8_t)

# define CMD_LS 0x1
# define CMD_CD 0x2
# define CMD_GET 0x3
# define CMD_PUT 0x4
# define CMD_PWD 0x5
# define CMD_QUIT 0x6

typedef struct sockaddr_in	sockaddr_in_t;

typedef struct		s_sock_data
{
	int				id;
	sockaddr_in_t	addr;
}					t_sock_data;

typedef struct		s_ftp_cmd
{
	uint8_t			cmd;
	char[ASC_SIZE]	ascii;
}					t_ftp_cmd;

void				cmd_ls(t_sock_data *sock);
void				cmd_cd(t_sock_data *sock, char *ascii);
void				cmd_get(t_sock_data *sock, char *ascii);
void				cmd_put(t_sock_data *sock, char *ascii);
void				cmd_pwd(t_sock_data *sock);
void				cmd_quit(t_sock_data *sock);
void				cmd_error(t_sock_data *sock, char *ascii);

void				pexit(char *str, int outno);
void				perr(char *str);

#endif
