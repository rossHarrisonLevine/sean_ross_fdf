/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:42:25 by rlevine           #+#    #+#             */
/*   Updated: 2017/01/04 18:01:44 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	int				i;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (i < (int)n)
	{
		if (one[i] != two[i])
			return ((unsigned char)one[i] - (unsigned char)two[i]);
		i++;
	}
	return (0);
}
