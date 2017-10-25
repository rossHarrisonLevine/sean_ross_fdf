/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:07:01 by sjones            #+#    #+#             */
/*   Updated: 2017/10/24 22:07:02 by sjones           ###   ########.fr       */
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
	mlx_key_hook(super->win->win, key_hook, super);
	mlx_loop(super->win->mlx);
}
