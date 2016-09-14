/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 13:37:09 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/14 19:18:35 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static void	command(uint8_t cmd, t_sock_data *sock, char *ascii)
{
	if (cmd == CMD_LS)
		cmd_ls(sock);
	else if (cmd == CMD_CD)
		cmd_cd(sock, ascii);
	else if (cmd == CMD_GET)
		cmd_get(sock, ascii);
	else if (cmd == CMD_PUT)
		cmd_put(sock, ascii);
	else if (cmd == CMD_PWD)
		cmd_pwd(sock);
	else if (cmd == CMD_QUIT)
		cmd_quit(sock);
	else
		cmd_error(sock, ascii);
}

static void	child_service(t_sock_data *sock)
{
	char	buf[BUF_SIZE];

	while (42) {
		ft_bzero(buf, BUF_SIZE);
		recv(sock->id, buf, BUF_SIZE, 0);
		command(*((uint8_t*)buf), sock, buf + sizeof(uint8_t));
	}
}

static void	service_spawner(t_sock_data *sock, socklen_t size)
{
	pid_t		pid;
	t_sock_data	child;

	if (listen(sock->id, 5) == -1)
		perr("Error: Listen failed\n");
	else
	{
		child.id = accept(sock->id, (void*)&(child.addr), &size);
		while ((pid = fork()) == -1)
			perr("Error: fork failed\n");
		if (pid == 0)
			child_service(&child);
	}
}

int			main(int argc, char *argv[])
{
	t_sock_data	sock;

	if (argc != 2)
		pexit("Usage: ./serveur port\n", 1);
	if ((sock.id = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		pexit("Error: server socket creation failed\n", 1);
	sock.addr.sin_port = htons(ft_atoi(argv[1]));
	sock.addr.sin_addr.s_addr = 0;
	if (bind(sock.id, (void*)&(sock.addr), sizeof(sock.addr)) < 0)
		pexit("Error: server port bind failed\n", 1);
	ft_putstr("Server listening on port ");
	ft_putnbr(ntohs(sock.addr.sin_port));
	ft_putstr(".\n");
	while (42)
		service_spawner(&sock, sizeof(sockaddr_in_t));
	return (0);
}
