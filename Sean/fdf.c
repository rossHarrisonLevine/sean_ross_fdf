/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:08:35 by sjones            #+#    #+#             */
/*   Updated: 2017/03/22 14:15:01 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_super	*init_super(t_win *w, t_map *m)
{
	t_super *s;

	if (!(s = (t_super*)malloc(sizeof(t_super))))
		return (NULL);
	if (s)
	{
		s->m = m;
		s->w = w;
	}
	return (s);
}

void	fdf(t_win *w, t_map *m)
{
	t_super *s;

	s = init_super(w, m);
	mlx_key_hook(w->win, key_hook, s);
	mlx_loop(w->mlx);
}
