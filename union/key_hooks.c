/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:59:53 by sjones            #+#    #+#             */
/*   Updated: 2017/10/25 14:52:29 by rlevine          ###   ########.fr       */
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
	if (key == KEY_1)
		rotate('x', 1, s->map->map);
	if (key == KEY_2)
		rotate('x', -1, s->map->map);
	if (key == KEY_3)
		rotate('y', 1, s->map->map);
	if (key == KEY_4)
		rotate('y', -1, s->map->map);
	if (key == KEY_5)
		rotate('z', 1, s->map->map);
	if (key == KEY_6)
		rotate('z', -1, s->map->map);
	draw_map(s);
	return (0);
}
