# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include "mlx_keys_macros.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
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
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				m;
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

typedef struct		s_super
{
	t_win			*win;
	t_map			*map;
	t_bresen		*bres;
}					t_super;

/*
** Initialization Functions
*/

t_super		*init_super(int fd);
t_map		*init_map(int fd);
t_point		*init_point(int x, int y, int z, long int color);
t_win		*init_win(int h, int w);
t_bresen	*init_bresen(t_point *p1, t_point *p2);

/*
**	Functions for running FdF
*/

int			key_hook(int key, t_super *s);
t_point		*read_map(int fd);

/*
**	Functions for testing purposes
*/

void		print_map(t_point *point);
