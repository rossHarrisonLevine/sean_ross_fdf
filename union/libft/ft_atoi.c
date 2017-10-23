/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 18:13:11 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/02 19:44:21 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *s)
{
	intmax_t	res;
	int			sign;
	char		*pos;

	pos = (char*)s;
	sign = 1;
	res = 0;
	while (*pos == ' ' || (*pos >= 9 && *pos <= 13))
		pos++;
	if (*pos == '-')
		sign = -1;
	if (*pos == '+' || *pos == '-')
		pos++;
	pos--;
	while (*++pos)
		if (ft_isdigit(*pos))
			res = res * 10 + (*pos - '0');
		else
			break ;
	res *= sign;
	return ((int)res);
}
