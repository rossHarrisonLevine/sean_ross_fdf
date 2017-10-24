/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 22:51:16 by rlevine           #+#    #+#             */
/*   Updated: 2017/10/24 11:17:26 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t t)
{
	void	*mem;

	mem = malloc(t);
	if (!mem)
		return (NULL);
	ft_bzero(mem, t);
	return (mem);
}
