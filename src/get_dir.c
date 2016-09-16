/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:11:40 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/09/16 11:48:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char	*get_root(void)
{
	static char	root[MAXPATHLEN] = "";

	if (*root != 0)
		return (root);
	if (getcwd(root, MAXPATHLEN) == NULL)
		pexit("Error: getcwd failed\n", 1);
	return (root);
}


char	*get_dir(void)
{
	static char	dir[MAXPATHLEN] = "";

	if (getcwd(dir, MAXPATHLEN) == NULL)
		pexit("Error: getcwd failed\n", 1);
	return (dir);
}

char	*basename(char *str)
{
	char	*tmp;

	if (str == NULL)
		return (NULL);
	tmp = str + ft_strlen(str);
	while (tmp != str)
	{
		if (*(tmp - 1) == '/')
			break;
		tmp--;
	}
	return tmp;
}
