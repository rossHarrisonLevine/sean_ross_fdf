/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:36:42 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/27 14:54:19 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t s)
{
	char	*ret;

	ret = (char *)ft_memalloc(1 + s);
	if (ret)
		return (ret);
	return (NULL);
}
