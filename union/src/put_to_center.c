/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 09:34:37 by sjones            #+#    #+#             */
/*   Updated: 2017/11/06 09:59:16 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_center(t_super *s)
{
	zoom(0.8 * (MAX(s->win->w / s->map->w, s->win->h / s->map->h)), s->map);
	translate_map((s->win->w - s->map->w) / 2, (s->win->h - s->map->h) / 2, \
			0, s->map->map);
}
