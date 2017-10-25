//#include "../get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "./minilibx_macos/mlx.h"
# define BUFF_SIZE 10
# define NULL_CHECK(x) if (!x) return (-1)

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	long int		color;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct		s_env
{
	int				tmp;
	char			*tit;
	int				min_h;
	int				max_h;
	float			curr_z;
	float			next_z;
	int				w;
	int				h;
	int				big;
	int				gap;
	int				i;
	int				j;
	float			max;
	float			maxside;
	void			*mlx;
	void			*win;
}					t_env;

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
	char			**map;
	int				width;
	int				height;
}					t_map;

/*
**	Functions for reading in input
*/
t_point		*init_point(int x, int y, int z, long int color);
t_point		*read_map(int fd);

/*
**	Functions for testing purposes
*/
void		print_map(t_point *point);
