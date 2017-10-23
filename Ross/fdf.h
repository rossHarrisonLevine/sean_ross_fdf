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

int get_next_line(const int fd, char **line);

typedef struct		s_env
{
	//t_points		**cart;
	int				tmp;
	char			*tit;
	int				x;
	int				y;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
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
	float			m;
	float			rise;
	float			run;
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
	int				x;
	int				y;
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
