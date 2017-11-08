/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:56:36 by sjones            #+#    #+#             */
/*   Updated: 2017/11/07 16:33:46 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	loop_hook_help(t_super *s)
{
	if (s->keys->n1 == true)
		rotate('x', 1, TH, s->map);
	if (s->keys->n2 == true)
		rotate('x', -1, TH, s->map);
	if (s->keys->n3 == true)
		rotate('y', 1, TH, s->map);
	if (s->keys->n4 == true)
		rotate('y', -1, TH, s->map);
	if (s->keys->n5 == true)
		rotate('z', 1, TH, s->map);
	if (s->keys->n6 == true)
		rotate('z', -1, TH, s->map);
	if (s->keys->up || s->keys->down || s->keys->right || s->keys->left || \
		s->keys->add || s->keys->sub || s->keys->n1 || s->keys->n2 || \
		s->keys->n3 || s->keys->n4 || s->keys->n5 || s->keys->n6)
		draw_map(s);
}

int			loop_hook(t_super *s)
{
	if (s->keys->esc == true)
		exit(0);
	if (s->keys->p == true)
		print_map(s->map->map);
	if (s->keys->up == true)
		translate_map(0, 1, 0, s->map->map);
	if (s->keys->down == true)
		translate_map(0, -1, 0, s->map->map);
	if (s->keys->right == true)
		translate_map(1, 0, 0, s->map->map);
	if (s->keys->left == true)
		translate_map(-1, 0, 0, s->map->map);
	if (s->keys->add == true)
		zoom(ZI, s->map);
	if (s->keys->sub == true)
		zoom(ZO, s->map);
	loop_hook_help(s);
	return (0);
}
