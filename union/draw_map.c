/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:55:36 by sjones            #+#    #+#             */
/*   Updated: 2017/10/25 16:32:02 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_row(t_point *row, t_win *win)
{
	while (row)
	{
		if (row->right)
			draw_line(row, row->right, win);
		if (row->down)
			draw_line(row, row->down, win);
		row = row->right;
	}
}

void		draw_map(t_super *s)
{
	t_point	*tmp;

	tmp = s->map->map;
	mlx_clear_window(s->win->mlx, s->win->win);
	while (tmp)
	{
		draw_row(tmp, s->win);
		tmp = tmp->down;
	}
}
