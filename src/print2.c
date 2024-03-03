/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:59:30 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 12:46:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static uint8_t		checkwhole(uint16_t **src, t_number *nbr, t_list *dict);
static uint8_t		checkpart(uint16_t **src, t_number *nbr, t_list *dict);
static uint8_t		checkpfx(uint16_t **src, t_number *nbr, t_list *dict);
static inline void	putseparator(uint64_t n);

uint8_t	checkcase(uint16_t **src, t_number *nbr, t_list *dict)
{
	if (checkwhole(src, nbr, dict))
		return (1);
	if (checkpart(src, nbr, dict))
		return (1);
	if (*src < &nbr->hundreds && checkpfx(src, nbr, dict))
		return (1);
	return (0);
}

static uint8_t	checkwhole(uint16_t **src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	char		*entry;

	n = ntou64(&nbr->ones, *src, nbr);
	entry = dict_getentry(dict, n);
	if (entry)
	{
		ft_putstr_fd(entry, 1);
		*src = &nbr->ones;
	}
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
	if (entry)
	{
		ft_putstr_fd(entry, 1);
		putseparator(n);
	}
	return (entry != NULL);
}

static uint8_t	checkpfx(uint16_t **src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	uint16_t	*tmp;
	char		*entry;

	n = ntou64(*src, *src, nbr);
	entry = dict_getentry(dict, n);
	if (entry)
	{
		ft_putstr_fd(entry, 1);
		ft_putchar_fd(' ', 1);
		n = 1;
		tmp = *src;
		while (tmp != &nbr->ones)
		{
			if (tmp < &nbr->thousands)
				n *= 1000;
			else
				n *= 10;
			tmp++;
		}
		ft_putstr_fd(dict_getentry(dict, n), 1);
		if (ntou64(&nbr->ones, *src + 1, nbr))
			ft_putstr_fd(", ", 1);
	}
	return (entry != NULL);
}

static inline void	putseparator(uint64_t n)
{
	if (n > 999)
		ft_putstr_fd(", ", 1);
	else if (n > 99)
		ft_putstr_fd(" and ", 1);
	else if (n > 19)
		ft_putchar_fd('-', 1);
}
