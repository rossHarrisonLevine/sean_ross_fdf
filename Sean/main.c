/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:15:35 by sjones            #+#    #+#             */
/*   Updated: 2017/05/30 16:00:01 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->max_y)
	{
		j = 0;
		while (j < map->max_x)
		{
			ft_putnbr(map->data[i][j]);
			j++;
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}

t_win	*init_win(int x_max, int y_max, char *name)
{
	t_win	*w;

	if (!(w = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, x_max, y_max, name);
	w->x_max = x_max ? x_max : 0;
	w->y_max = y_max ? y_max : 0;
	return (w);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_win	*win;
	int		fd;

	if (ac != 4)
	{
		ft_putendl("Usage: int fd, unsigned int window_x_max, unsigned int window_y_max");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		win = init_win(ft_atoi(av[2]), ft_atoi(av[3]), "Navel Tree");
		map = read_map(fd);
		put_map(map);
		fdf(win, map);
	}
	mlx_loop(win->mlx);
	return (0);
}
