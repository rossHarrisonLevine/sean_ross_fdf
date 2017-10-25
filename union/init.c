/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:04:24 by sjones            #+#    #+#             */
/*   Updated: 2017/10/24 22:04:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_super		*init_super(int fd)
{
	t_super	*super;

	if (!(super = (t_super*)malloc(sizeof(t_super))))
	{
		perror("not enough space for a t_super");
		return (NULL);
	}
	super->win = init_win(1000, 1000);
	super->map = init_map(fd);
	super->bres = NULL;
	return (super);
}

t_map		*init_map(int fd)
{
	t_map	*map;
	t_point	*tmp;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
	{
		perror("not enough space for a t_map");
		return (NULL);
	}
	map->map = read_map(fd);
	map->w = 0;
	map->h = 0;
	tmp = map->map;
	while (tmp)
	{
		tmp = tmp->down;
		map->h++;
	}
	while (tmp)
	{
		tmp = tmp->right;
		map->h++;
	}
	return (map);
}

t_win		*init_win(int h, int w)
{
	t_win	*win;

	if (!(win = (t_win*)malloc(sizeof(t_win))))
	{
		perror("not enough space for a t_win\n");
		return (NULL);
	}
	win->tit = "I'm Mister Window, look at me!!!";
	win->h = h;
	win->w = w;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->w, win->h, win->tit);
	return (win);
}

t_point		*init_point(int x, int y, int z, long int color)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
	{
		perror("Not enough space for a t_point\n");
		return (NULL);
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	point->right = NULL;
	point->down = NULL;
	return (point);
}
