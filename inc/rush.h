/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 15:22:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include "libft.h"
# include <fcntl.h>
# define E_ARGS 1
# define E_DICT 2

typedef struct t_dict
{
	uint64_t	val;
	char		*str;
}	t_dict;

// dict.c
int		getdict(const char *fname, t_list **dict);

#endif
