/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:35:11 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/27 14:57:30 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	int		i;
	size_t	t;

	i = 10;
	t = 0;
	if (ft_isneg(n))
		t++;
	if (ft_abs(n) < (unsigned int)10)
		return (t + 1);
	t += 2;
	while (!((ft_abs(n) / i) < 10))
	{
		i *= 10;
		t++;
	}
	return (t);
}
