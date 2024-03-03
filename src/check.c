/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 12:31:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static uint8_t	checkvals(t_number *nbr, t_list *dict);
static uint8_t	checkval(uint16_t n, t_list *dict);

uint8_t	checkdict(char *n, t_list *dict)
{
	t_number	nbr;

	getnumber(n, &nbr);
	if (!checkvals(&nbr, dict))
		return (0);
	return (1);
}

static uint8_t	checkvals(t_number *nbr, t_list *dict)
{
	uint16_t	*src;

	src = &nbr->quints;
	while (src <= &nbr->thousands)
	{
		if (*src && !checkval(*src, dict))
		{
			if (!checkspecial(&src, nbr, dict))
				return (0);
		}
		src++;
	}
	if (src == &nbr->hundreds)
	{
		if (!checkval(ntou64(&nbr->ones, src, nbr), dict))
		{
			if (!checkspecial(&src, nbr, dict))
				return (0);
		}
	}
	return (1);
}

static uint8_t	checkval(uint16_t n, t_list *dict)
{
	if (n == 0)
		return (1);
	if (n > 99)
	{
		if (!dict_getentry(dict, HNDR) || !dict_getentry(dict, n / 100))
			return (0);
		n %= 100;
	}
	if (n > 9)
	{
		if (n > 19 && !dict_getentry(dict, n - (n % 10)))
			return (0);
		else if (n < 20 && !dict_getentry(dict, n))
			return (0);
		n %= 10;
	}
	if (!dict_getentry(dict, n))
		return (0);
	return (1);
}
