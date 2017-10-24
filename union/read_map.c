#include "fdf.h"

static struct t_point	make_line(char **l_split, depth)
{
	struct t_point *head;
	struct t_point *new;
	struct t_point *tmp;
	int i;

	i = 1;
	head = init_point(0, depth, get_num(l_split[0]), get_col(l_split[i]));
	tmp = head;
	while (l_split[i])
	{
		new = init_point(i, j, get_num(l_split[i]), get_col(l_split[i]));
		tmp->right = new;
		tmp = tmp->right;
	}
	return head;
}

static void				add_line(struct t_point *head, struct t_point *new)
{
	struct t_point tmp;

	if (!head)
		head = new;
	tmp = head;
	while (tmp->down)
		tmp = tmp->down;
	while (tmp->next)
	{
		tmp->down = new;
		tmp = tmp->right;
		new = new->right;
	}
}

struct t_point			*read_map(int fd)
{
	struct t_point	*head;
	struct t_point	*new;
	char			*line;
	char			**l_split;
	int				depth;

	head = NULL;
	depth = 0;
	while (get_next_line(fd, &line) > 0)
	{
		l_split = str_split(line, ' ');
		add_line(head, make_line(l_split, depth));
		free l_split;
		depth++;
	}
	return head;
}
