/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:59:53 by sjones            #+#    #+#             */
/*   Updated: 2017/03/22 14:38:06 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, t_super *s)
{
	if (key == KEY_ESCAPE)
		exit (0);
//	if (key == KEY_X)
//		draw_x_view(win, map);
//	if (key == KEY_Y)
//		draw_y_view(win, map);
	if (key == KEY_I)
		draw_iso_view(s->w, s->m);
	return (0);
}
