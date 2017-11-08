/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 09:34:37 by sjones            #+#    #+#             */
/*   Updated: 2017/11/07 17:30:42 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_center(t_super *s)
{
	rotate('z', 1, PI, s->map);
	rotate('y', -1, 5*PI/6, s->map);
	rotate('x', -1, PI/6, s->map);
	zoom(0.8 * (MIN(s->win->w / s->map->w, s->win->h / s->map->h)), s->map);
}
