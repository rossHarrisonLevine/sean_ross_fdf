/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:07:01 by sjones            #+#    #+#             */
/*   Updated: 2017/10/25 16:27:31 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_super *super;

	if (ac != 2)
	{
		write(1, "Put a map in please! :]\n", 24);
		return (0);
	}
	super = init_super(open(av[1], O_RDONLY));
	draw_map(super);
	mlx_hook(super->win->win, 2, 0, key_press_hook, super);
	mlx_hook(super->win->win, 3, 0, key_release_hook, super);
	mlx_loop_hook(super->win->mlx, loop_hook, super);
	mlx_loop(super->win->mlx);
}
