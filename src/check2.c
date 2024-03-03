/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:41:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 12:05:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static uint8_t	checkwhole(uint16_t	**src, t_number *nbr, t_list *dict);
static uint8_t	checkpart(uint16_t **src, t_number *nbr, t_list *dict);
static uint8_t	checkpfx(uint16_t **src, t_number *nbr, t_list *dict);

uint8_t	checkspecial(uint16_t **src, t_number *nbr, t_list *dict)
{
	if (checkwhole(src, nbr, dict))
		return (1);
	if (checkpart(src, nbr, dict))
		return (1);
	if (*src < &nbr->hundreds && checkpfx(src, nbr, dict))
		return (1);
	return (0);
}

static uint8_t	checkwhole(uint16_t	**src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	char		*entry;

	n = ntou64(&nbr->ones, *src, nbr);
	entry = dict_getentry(dict, n);
	if (entry)
		*src = &nbr->ones;
	return (entry != NULL);
}

static uint8_t	checkpart(uint16_t **src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	uint16_t	*tmp;
	char		*entry;

	n = ntou64(*src, *src, nbr);
	tmp = &nbr->ones;
	while (tmp > *src)
	{
		if (tmp > &nbr->thousands)
			n *= 10;
		else
			n *= 1000;
		tmp--;
	}
	entry = dict_getentry(dict, n);
	return (entry != NULL);
}

static uint8_t	checkpfx(uint16_t **src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	char		*entry;

	n = ntou64(*src, *src, nbr);
	entry = dict_getentry(dict, n);
	return (entry != NULL);
}
