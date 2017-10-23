/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:31:14 by sjones            #+#    #+#             */
/*   Updated: 2017/05/30 15:59:52 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_line *l, t_win *w)
{
	while (l->x != l->x2 && l->y != l->y2)
	{
		mlx_pixel_put(w->mlx, w->win, l->x, l->y, 0x00FF00FF);
		l->e2 = l->e1;
		if ((l->e2 > -(l->dx)) ? (l->e1 -= l->dy) : (l->e1 += 0))
			l->x += l->sx;
		if ((l->e2 < l->dy) ? (l->e1 += l->dx) : (l->e1 += 0))
			l->y += l->sy;
	}
}


/*
int		main()
{
	t_line	*line1;
	t_line	*line2;
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1000, 1000, "2 line test");
	line1 = init_line(1, 1, 999, 999);
	line2 = init_line(100, 900, 700, 100);
	put_line(line1, win);
	put_line(line2, win);
	mlx_loop(win.mlx);
	return (0);
}
*/
