/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/03 12:34:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	putspecial(uint16_t **src, t_number *nbr, t_list *dict);
static void	putnumber(uint16_t *src, t_number *nbr, t_list *dict);
static void	putprefix(uint16_t *src, t_list *dict);

void	print(char *n, t_list *dict)
{
	t_number	nbr;
	uint16_t	*src;

	getnumber(n, &nbr);
	src = &nbr.quints;
	while (src)
	{
		if (*src)
		{
			if (!checkcase(&src, &nbr, dict))
			{
				if (src == &nbr.hundreds || src == &nbr.tens || src == &nbr.ones)
					putspecial(&src, &nbr, dict);
				else
					putnumber(src, &nbr, dict);
			}
		}
		if (src != &nbr.ones)
			src++;
		else
			src = NULL;
	}
	ft_putchar_fd('\n', 1);
}

static void	putspecial(uint16_t **src, t_number *nbr, t_list *dict)
{
	if (*src == &nbr->hundreds)
	{
		ft_putstr_fd(dict_getentry(dict, **src), 1);
		ft_putchar_fd('-', 1);
		ft_putstr_fd(dict_getentry(dict, HNDR), 1);
	}
	else if (*src == &nbr->tens && **src > 1)
		ft_putstr_fd(dict_getentry(dict, **src * 10), 1);
	else if (*src == &nbr->tens)
	{
		ft_putstr_fd(dict_getentry(dict, *(*src + 1) + 10), 1);
		(*src)++;
	}
	else
		ft_putstr_fd(dict_getentry(dict, **src), 1);
	if (*src == &nbr->hundreds && (*(*src + 1) || *(*src + 2)))
		ft_putstr_fd(" and ", 1);
	if (*src == &nbr->tens && *(*src + 1))
		ft_putchar_fd('-', 1);
}

static void	putnumber(uint16_t *src, t_number *nbr, t_list *dict)
{
	uint64_t	n;
	uint16_t	*tmp;

	putprefix(src, dict);
	n = 1;
	tmp = src;
	while (tmp != &nbr->ones)
	{
		if (tmp < &nbr->thousands)
			n *= 1000;
		else
			n *= 10;
		tmp++;
	}
	ft_putstr_fd(dict_getentry(dict, n), 1);
	if (ntou64(&nbr->ones, src + 1, nbr))
		ft_putstr_fd(", ", 1);
}

static void	putprefix(uint16_t *src, t_list *dict)
{
	if (*src > 99)
	{
		ft_putstr_fd(dict_getentry(dict, *src / 100), 1);
		ft_putchar_fd('-', 1);
		ft_putstr_fd(dict_getentry(dict, HNDR), 1);
		*src %= 100;
		if (*src)
			ft_putstr_fd(" and ", 1);
	}
	if (*src > 9)
	{
		if (*src > 19)
			ft_putstr_fd(dict_getentry(dict, *src - (*src % 10)), 1);
		else
		{
			ft_putstr_fd(dict_getentry(dict, *src), 1);
			*src = 0;
		}
		*src %= 10;
		if (*src)
			ft_putchar_fd('-', 1);
	}
	if (*src)
		ft_putstr_fd(dict_getentry(dict, *src), 1);
	ft_putchar_fd(' ', 1);
}
