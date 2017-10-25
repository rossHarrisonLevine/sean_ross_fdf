/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:59:53 by sjones            #+#    #+#             */
/*   Updated: 2017/10/24 22:11:53 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, t_super *s)
{
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_P)
		print_map(s->map->map);
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
