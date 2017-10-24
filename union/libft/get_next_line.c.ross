/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:38:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/29 16:20:10 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*check_fd(t_list **used, int fd)
{
	t_list			*tmp;

	tmp = *used;
	while (tmp)
	{
		if ((size_t)fd == tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", 1);
	NULL_GUARD(tmp);
	tmp->content_size = (size_t)fd;
	ft_lstadd(used, tmp);
	tmp = *used;
	return (tmp);
}

int			snip(t_list *cur, char **buf)
{
	int				ret;
	char			*tmp;

	while (ft_strchr(*buf, '\n') == NULL && \
				(ret = read(cur->content_size, *buf, BUFF_SIZE)) > 0)
	{
		tmp = cur->content;
		cur->content = ft_strjoin(tmp, *buf);
		NULL_CHECK(cur->content);
		ft_strdel(&tmp);
		ft_strclr(*buf);
	}
	ft_strdel(buf);
	if (ret == -1)
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*used;
	char			*buf;
	t_list			*cur;
	char			*tmp;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE)) || BUFF_SIZE < 0 \
			|| !(cur = check_fd(&used, fd)) || snip(cur, &buf) == -1)
		return (-1);
	if (!cur->content)
		return (0);
	if ((buf = ft_strchr((char*)cur->content, '\n')) != NULL)
	{
		*line = ft_strsub(cur->content, 0, buf - (char*)cur->content);
		NULL_CHECK(*line);
		tmp = cur->content;
		cur->content = ft_strdup(buf + 1);
		NULL_CHECK(cur->content);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(cur->content);
	cur->content = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
