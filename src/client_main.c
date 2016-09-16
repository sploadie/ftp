/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 13:37:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 12:48:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void		output_recv(t_sock_data *sock, size_t size)
{
	char	buf[size + 1];

	recv(sock->id, buf, size, 0);
	buf[size] = 0;
	ft_putendl(buf);
}

void		handle_cmd(t_sock_data *sock, t_ftp_cmd *cmd)
{
	size_t	size;

	if (cmd->cmd == 0x0)
		return (perr("Error: Unknown command\n"));
	send(sock->id, cmd, BUF_SIZE, 0);
	if (cmd->cmd == CMD_PUT)
		client_put(sock, cmd);
	if (cmd->cmd == CMD_GET)
		client_get(sock, cmd);
	recv(sock->id, &size, sizeof(size_t), 0);
	output_recv(sock, size);
	if (cmd->cmd == CMD_QUIT)
		pexit("Goodbye!\n", 0);
}

t_ftp_cmd	*parse_cmd(t_ftp_cmd *cmd, char *str)
{
	char	*tmp;

	if (ft_strchr(str, '\n') != NULL)
		*ft_strchr(str, '\n') = 0;
	if (ft_strncmp("ls", str, 3) == 0)
		cmd->cmd = CMD_LS;
	else if (ft_strncmp("cd ", str, 3) == 0 || ft_strncmp("cd", str, 3) == 0)
		cmd->cmd = CMD_CD;
	else if (ft_strncmp("get ", str, 4) == 0)
		cmd->cmd = CMD_GET;
	else if (ft_strncmp("put ", str, 4) == 0)
		cmd->cmd = CMD_PUT;
	else if (ft_strncmp("pwd", str, 4) == 0)
		cmd->cmd = CMD_PWD;
	else if (ft_strncmp("quit", str, 5) == 0)
		cmd->cmd = CMD_QUIT;
	else
		cmd->cmd = 0x0;
	if ((tmp = ft_strchr(str, ' ')) == NULL)
		tmp = str + ft_strlen(str);
	else
		tmp++;
	ft_strcpy(cmd->ascii, tmp);
	return (cmd);
}

void		client_prompt(t_sock_data *sock)
{
	int			ret;
	t_ftp_cmd	cmd;

	ft_putstr("\x1b[32mclient >\x1b[0m ");
	ret = read(0, cmd.ascii, ASC_SIZE - 1);
	if (ret == 0)
		write(1, "\n", 1);
	if (ret == 1)
		return ;
	cmd.ascii[ret] = 0;
	handle_cmd(sock, parse_cmd(&cmd, cmd.ascii));
}

int			main(int argc, char *argv[])
{
	t_sock_data		sock;
	struct hostent	*host;

	if (argc != 3)
		pexit("Usage: ./client machine port\n", 1);
	if ((sock.id = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		pexit("Error: client socket creation failed\n", 1);
	sock.addr.sin_family = AF_INET;
	sock.addr.sin_port = htons(ft_atoi(argv[2]));
	if ((host = gethostbyname(argv[1])) == NULL)
		pexit("Error: unknown machine\n", 1);
	ft_memcpy(&sock.addr.sin_addr.s_addr, host->h_addr, host->h_length);
	if (connect(sock.id, (void*)&(sock.addr), sizeof(sock.addr)) < 0)
		pexit("Error: client server connection failed\n", 1);
	ft_putstr("Client connected to server\n");
	while (42)
		client_prompt(&sock);
	return (0);
}
