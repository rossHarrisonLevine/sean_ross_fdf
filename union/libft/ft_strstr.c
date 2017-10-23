/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:34:42 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/27 15:02:42 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		l;
	int		b;

	b = 0;
	l = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[b])
	{
		if (little[l] == big[b])
		{
			while (little[l] == big[l + b] && little[l])
			{
				l++;
			}
			if (little[l] == '\0')
				return ((char*)&big[b]);
		}
		l = 0;
		b++;
	}
	return (NULL);
}
