/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:06:48 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/27 14:50:21 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *c1;
	char *c2;

	if (dst > src && dst <= src + len)
	{
		if (len == 0 || src == dst)
			return (ft_memcpy(dst, src, len));
		c1 = (char *)dst;
		c2 = (char *)src;
		while (len--)
			c1[len] = c2[len];
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
