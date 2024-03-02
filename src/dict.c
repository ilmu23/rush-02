/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:19:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 15:48:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static t_dict	*dict_entry(char **line);
static char		**getentry(int fd, char *err);
static int		isvalid(const char *line, size_t *i, size_t *j);

int	getdict(const char *fname, t_list **dict)
{
	char	**line;
	char	err;
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 1)
		return (0);
	err = 0;
	line = getentry(fd, &err);
	while (line && !err)
	{
		if (*line[0] != '-'
			&& (ft_atou64(line[0]) || ft_strequals(line[0], "0")))
			ft_lstadd_back(dict, ft_lstnew(dict_entry(line)));		
		line = getentry(fd, &err);
	}
	close(fd);
	return (!err);
}

static t_dict	*dict_entry(char **line)
{
	t_dict	*out;

	out = ft_push(ft_alloc(sizeof(t_dict)));
	if (!out)
		return (NULL);
	out->val = ft_atou64(line[0]);
	out->str = ft_push(ft_strdup(line[1]));
	ft_popblk(line);
	ft_popblk(line[0]);
	ft_popblk(line[1]);
	ft_popblk(out);
	return (out);
}

static char		**getentry(int fd, char *err)
{
	char	**out;
	char	*line;
	size_t	i;
	size_t	j;

	line = ft_push(ft_strtrim(get_next_line(fd), "\n"));
	if (!line)
		return (NULL);
	out = ft_push(ft_calloc(3, sizeof(char *)));
	if (!out)
		*err = 1;
	i = 0;
	if (!isvalid(line, &i, &j))
	{
		*err = 1;
		return (NULL);
	}
	out[0] = ft_push(ft_substr(line, 0, i));
	out[1] = ft_push(ft_strdup(&line[j]));
	if (!out[0] || !out[1])
		*err = 1;
	return (out);
}

static int	isvalid(const char *line, size_t *i, size_t *j)
{
	while (ft_isdigit(line[*i]))
		(*i)++;
	*j = *i;
	while (ft_isspace(line[*j]))
		(*j)++;
	if (line[*j] != ':')
		return (0);;
	(*j)++;
	while (ft_isspace(line[*j]))
		(*j)++;
	return (1);
}
