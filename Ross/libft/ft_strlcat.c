/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:47:22 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/02 16:24:25 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	int		dest_len;
	int		src_len;
	int		empty_space;
	int		to_copy;
	char	*pos;

	dest_len = ft_strlen(s1);
	src_len = ft_strlen((char*)s2);
	empty_space = n - dest_len - 1;
	if (empty_space <= 0)
		return (n + src_len);
	if (src_len >= empty_space)
		to_copy = empty_space;
	else
		to_copy = src_len;
	pos = (char*)ft_memchr(s1, '\0', dest_len + 1);
	ft_memcpy(pos, s2, to_copy);
	*(pos + to_copy) = '\0';
	return (dest_len + src_len);
}
