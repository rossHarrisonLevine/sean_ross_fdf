/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:06:06 by sjones            #+#    #+#             */
/*   Updated: 2017/03/22 14:00:42 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx_keys_macros.h"
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
// compile with minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

typedef struct		s_map
{
	int				**data;
	int				**trans_i;
	int				**trans_j;
	int				max_x;
	int				max_y;
	int				max_z;
}					t_map;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				x_max;
	int				y_max;
}					t_win;

typedef struct		s_super
{
	t_map			*m;
	t_win			*w;
}					t_super;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				e1;
	int				e2;
}					t_line;

t_map	*read_map(int fd);
t_map	*init_map(void);
t_win	*init_win(int x_max, int y_max, char *name);
t_line	*init_line(int x1, int y1, int x2, int y2);
t_super	*init_super(t_win *w, t_map *m);
void	fdf(t_win *w, t_map *m);
int		key_hook(int key, t_super *s);
void	put_line(t_line *l, t_win *w);
void	draw_iso_view(t_win *w, t_map *m);
void	translate_i2iso(t_map *m, t_win *w);


#endif
