/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:19:09 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/17 13:31:04 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bs;
	size_t			i;

	bs = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bs[i] = c;
		i++;
	}
	return (bs);
}
