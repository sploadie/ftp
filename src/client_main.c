/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 13:37:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/14 19:50:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

t_ftp_cmd	*parse_cmd(t_ftp_cmd *cmd)
{
	char	*tmp;
	size_t	len;

	if ((tmp = ft_strchr(cmd->ascii, ' ')) == NULL)
		tmp = cmd->ascii + ft_strlen(cmd->ascii);
	len = tmp - cmd->ascii;
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
	ft_putstr(cmd.ascii);
	handle_cmd(sock, parse_cmd(&cmd));
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
