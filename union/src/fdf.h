/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:07:44 by sjones            #+#    #+#             */
/*   Updated: 2017/10/28 15:27:40 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "mlx_keys_macros.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>

# define ABS(x) (x < 0) ? -x : x

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	long int		color;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct		s_win
{
	char			*tit;
	int				w;
	int				h;
	void			*mlx;
	void			*win;
}					t_win;

typedef	struct		s_bresen
{
	int				flip;
	int				yw;
	int				x;
	int				y;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			m;
	float			rise;
	float			run;
	float			offset;
	float			threshold;
	float			thresholdinc;
	float			adjust;
	int				color1;
	int				color2;
	int				dr;
	int				dg;
	int				db;
	int				color;
}					t_bresen;

typedef struct		s_map
{
	t_point			*map;
	int				w;
	int				h;
}					t_map;

typedef struct		s_keys
{
	bool			esc;
	bool			p;
	bool			up;
	bool			down;
	bool			right;
	bool			left;
	bool			add;
	bool			sub;
	bool			n1;
	bool			n2;
	bool			n3;
	bool			n4;
	bool			n5;
	bool			n6;
}					t_keys;

typedef struct		s_super
{
	t_win			*win;
	t_map			*map;
	t_bresen		*bres;
	t_keys			*keys;
}					t_super;

/*
** Initialization Functions
*/

t_super				*init_super(int fd);
t_map				*init_map(int fd);
t_point				*init_point(int x, int y, int z, long int color);
t_win				*init_win(int h, int w);
t_bresen			*init_bresen(t_point *p1, t_point *p2);
t_keys				*init_keys(void);

/*
**	Functions for running FdF
*/

int					key_press_hook(int key, t_super *s);
int					key_release_hook(int key, t_super *s);
int					loop_hook(t_super *s);
t_point				*read_map(int fd);
void				draw_map(t_super *s);
void				draw_line(t_point *p1, t_point *p2, t_win *win);

/*
**	Movement funtions
*/

void				translate_map(float x, float y, t_point *point);
void				zoom(float mult, t_map *point);
void				rotate(char c, int dir, t_point *point);

/*
**	Functions for testing purposes
*/

void				print_map(t_point *point);

#endif
