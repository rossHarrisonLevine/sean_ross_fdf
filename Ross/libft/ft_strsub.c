/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:37:17 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/02 16:48:44 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	new = ft_strnew(len);
	if (new && s)
	{
		new = ft_strncpy(new, &s[start], len);
		return (new);
	}
	return (NULL);
}
