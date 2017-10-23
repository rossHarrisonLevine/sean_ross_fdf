/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:22:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/06/30 15:02:25 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*ptr;
	size_t		i;
	int			neg;

	neg = n;
	if (n == (-2147483648))
	{
		ptr = ft_strdup("-2147483648");
		return (ptr);
	}
	i = ft_nbrlen(n);
	ptr = ft_strnew(i);
	if (ptr)
	{
		n = ft_abs(n);
		while (i--)
		{
			ptr[i] = (n % 10) + '0';
			n /= 10;
		}
		if (ft_isneg(neg))
			ptr[0] = '-';
		return (ptr);
	}
	return (NULL);
}
