/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:59:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/07 16:23:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ptrswap(void *a, void *b)
{
	void	*temp;
	void	**saf_a;
	void	**saf_b;

	saf_a = a;
	saf_b = b;
	temp = *saf_a;
	*saf_a = *saf_b;
	*saf_b = temp;
}
