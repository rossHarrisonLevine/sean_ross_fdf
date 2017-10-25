/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:59:53 by sjones            #+#    #+#             */
/*   Updated: 2017/10/25 13:25:33 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, t_super *s)
{
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_P)
		print_map(s->map->map);
	if (key == KEY_UP)
		translate_map(0, 1, s->map->map);
	if (key == KEY_DOWN)
		translate_map(0, -1, s->map->map);
	if (key == KEY_RIGHT)
		translate_map(1, 0, s->map->map);
	if (key == KEY_LEFT)
		translate_map(-1, 0, s->map->map);
	if (key == KEY_PAD_ADD)
		zoom(2, s->map->map);
	if (key == KEY_PAD_SUB)
		zoom(0.5, s->map->map);
	draw_map(s);
	return (0);
}
/*
** call key press whatever to modify whatever you want in struct s
**	if (key == KEY_X)
**		draw_x_view(win, map);
**	if (key == KEY_Y)
**		draw_y_view(win, map);
**	if (key == KEY_I)
**		draw_iso_view(s->w, s->m);
*/
