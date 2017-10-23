/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:03:26 by sjones            #+#    #+#             */
/*   Updated: 2017/05/30 15:40:40 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int		max_z_in_x(t_map, int x)
{
	int i;
	int	z;

	i = 0;
	while (i <= m->max_y)
	{
		z = z < map[x][i] ? map[x][i] : z;
	}
	return (z);
}

int		max_z_in_y(t_map, int y)
{
	int i;
	int z;

	i = 0;
	while (i <= m->may_x)
	{
		z = z < map[i][y] ? map[x][i] : z;
	}
	return (z);
}
*/
void	translate_i2iso(t_map *m, t_win *w)
{
	int	scal_x;
	int	scal_y;
	int i;
	int j;

	ft_putendl("did I get here as well?");
	scal_x = 40; //(m->max_x / w->x_max);
	scal_y = 40; //(m->max_z / w->y_max);
	i = 0;
	while (i < m->max_y)
	{
		j = 0;
		while (j < m->max_x)
		{
			m->trans_i[i][j] = i * scal_x * cos(-0.8) - j * scal_y * sin(-0.8) + scal_x;
			m->trans_j[i][j] = (i * scal_x * sin(-0.8) + j * scal_y * cos(-0.8)) / 2
								+ (w->x_max / 2) - m->data[i][j] * 4;
			j++;
		}
		i++;
	}
}

void	draw_iso_view(t_win *w, t_map *m)
{
	t_line	*l;
	int		i;
	int		j;

	ft_putendl("did I get here?");
	translate_i2iso(m, w);
	i = 0;
	while (i < m->max_y - 1)
	{
		j = 0;
		while (j < m->max_x - 1)
		{
			l = init_line(m->trans_i[i][j], m->trans_j[i][j], m->trans_i[i][j + 1], m->trans_j[i][j + 1]);
			put_line(l, w);
			j++;
		}
		i++;
	}
}
/*
void	draw_top_view(t_win *w, t_map *m)
{

}

void	draw_x_view(t_win *w, t_map *m)
{
	t_line *l;
	int i;
	int	j;
	i = 0;
	while (i < m->max_x)
	{
		j = 0;
		while (j < m->max_y)
		{
			l = init_line(i * sx, j * sy, (i + 1) * sx, j * sy * max_z_in_x(map, i))
			put_line(l, w);
		}
	}
}
*/
