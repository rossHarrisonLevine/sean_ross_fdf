# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include "mlx_keys_macros.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>

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
	int				slope;
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
	float			tmp;
	float			adjust;
	float			delta;
	int				colorgrade;
	float			color;
	float			range;
	char			*str;
	char			**coord;
	char			*line;
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

t_super		*init_super(int fd);
t_map		*init_map(int fd);
t_point		*init_point(int x, int y, int z, long int color);
t_win		*init_win(int h, int w);
t_bresen	*init_bresen(t_point *p1, t_point *p2);
t_keys		*init_keys(void);

/*
**	Functions for running FdF
*/

int			key_hook(int key, t_super *s);
t_point		*read_map(int fd);
void		draw_map(t_super *s);
void		draw_line(t_point *p1, t_point *p2, t_win *win);

/*
**	Movement funtions
*/

void		translate_map(int x, int y, t_point *point);
void		zoom(float mult, t_point *point);
void        rotate(char c, int dir, t_point *point);

/*
**	Functions for testing purposes
*/

void		print_map(t_point *point);
