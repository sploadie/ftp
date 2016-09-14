/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:10:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/20 11:36:28 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**wary_init(char const *s, char c)
{
	long long		i;
	long long		beg;
	char			**wary;
	unsigned int	wcount;

	wcount = 0;
	beg = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (beg != i - 1)
				wcount++;
			beg = i;
		}
		i++;
	}
	if (beg != i - 1)
		wcount++;
	wary = (char **)malloc((wcount + 1) * sizeof(char*));
	if (!wary)
		return (NULL);
	wary[wcount] = NULL;
	return (wary);
}

char		**ft_strsplit(char const *s, char c)
{
	long long		i;
	long long		beg;
	char			**wary;
	unsigned int	wcount;

	if (!s || !(wary = wary_init((char*)s, c)))
		return (NULL);
	wcount = 0;
	beg = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (beg != i - 1)
				wary[wcount++] = ft_strsub((char*)s, beg + 1, (i - beg) - 1);
			beg = i;
		}
		i++;
	}
	if (beg != i - 1)
		wary[wcount++] = ft_strsub((char*)s, beg + 1, (i - beg) - 1);
	return (wary);
}
