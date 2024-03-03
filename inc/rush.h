/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 09:36:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include "libft.h"
# include <fcntl.h>
# define E_ARGS 1
# define E_DICT 2

typedef struct s_number
{
	uint16_t	quints;
	uint16_t	quads;
	uint16_t	trips;
	uint16_t	bills;
	uint16_t	mills;
	uint16_t	thousands;
	uint16_t	hundreds;
	uint16_t	tens;
	uint16_t	ones;
}	t_number;

typedef struct s_dict
{
	uint64_t	val;
	char		*str;
}	t_dict;

// dict.c
char		*dict_getentry(t_list *dict, uint64_t val);
int			parsedict(const char *fname, t_list **dict);

// print.c
void		print(char *n, t_list *dict);

// number.c
uint64_t	ntou64(uint16_t *src, uint16_t *limit, t_number *nbr);
void		getnumber(char *n, t_number *nbr);

#endif
