#include "fdf.h"

static int		get_num(char *line)
{
	char tmp[ft_strlen(line)];
	int i;

	i = 0;
	while (line[i] && line[i] != ',')
	{
		tmp[i] = line[i];
		i++;
	}
	return ft_atoi(tmp);
}

static long int	get_col(char *line)
{
	char tmp[ft_strlen(line)];
	int i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (!(line[i]))
		return 0;
	else
	{
		while (line[i])
		{
			tmp[i] = line[i];
			i++;
		}
		return strtol(tmp, NULL, 16);
	}
}

static t_point	*make_line(char **l_split, int depth)
{
	t_point	*head;
	t_point	*new;
	t_point	*tmp;
	int i;

	i = 1;
	head = init_point(0, depth, get_num(l_split[0]), get_col(l_split[0]));
	tmp = head;
	while (l_split[i])
	{
		new = init_point(i, depth, get_num(l_split[i]), get_col(l_split[i]));
		tmp->right = new;
		tmp = tmp->right;
	}
	return head;
}

static void		add_line(t_point *head, t_point *new)
{
	t_point	*tmp;

	if (!head)
		head = new;
	tmp = head;
	while (tmp->down)
		tmp = tmp->down;
	while (tmp->right)
	{
		tmp->down = new;
		tmp = tmp->right;
		new = new->right;
	}
}

t_point			*read_map(int fd)
{
	t_point	*head;
	t_point	*new;
	char	*line;
	char	**l_split;
	int		depth;

	head = NULL;
	depth = 0;
	while (get_next_line(fd, &line) > 0)
	{
		l_split = ft_strsplit(line, ' ');
		add_line(head, make_line(l_split, depth));
		free(l_split);
		depth++;
	}
	return head;
}
