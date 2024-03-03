/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 11:00:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	getsmall(char *n, uint16_t **dst, ssize_t *i, t_number *nbr);
static void	getbig(char *n, uint16_t **dst, ssize_t *i);

uint64_t	ntou64(uint16_t *src, uint16_t *limit, t_number *nbr)
{
	uint64_t	n;
	uint64_t	mult;

	mult = 10;
	n = *src--;
	while (src >= limit)
	{
		n += *src * mult;
		if (src > &nbr->thousands)
			mult *= 10;
		else
			mult *= 1000;
		src--;
	}
	return (n);
}

void	getnumber(char *n, t_number *nbr)
{
	uint16_t	*dst;
	ssize_t		i;

	ft_bzero(nbr, sizeof(t_number));
	dst = &nbr->ones;
	i = ft_strlen(n) - 1;
	while (*n)
	{
		if (dst == &nbr->ones || dst == &nbr->tens || dst == &nbr->hundreds)
			getsmall(n, &dst, &i, nbr);
		else
			getbig(n, &dst, &i);
		dst--;
	}
}

static void	getsmall(char *n, uint16_t **dst, ssize_t *i, t_number *nbr)
{
	**dst = n[*i] - '0';
	n[(*i)--] = '\0';
	if (*dst == &nbr->hundreds && *i >= 2)
		*i -= 2;
	else if (*dst == &nbr->hundreds)
		*i -= *i;
}

static void	getbig(char *n, uint16_t **dst, ssize_t *i)
{
	**dst = ft_atou64(&n[*i]);
	n[*i] = '\0';
	if (*i >= 3)
		*i -= 3;
	else
		*i -= *i;
}
