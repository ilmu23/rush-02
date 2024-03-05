/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:08:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/05 11:09:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static uint8_t	checkargs(int16_t argc, char *n);
static uint8_t	checknbr(char *n);
static char		*trimzeros(char *n);

int	main(int argc, char **argv)
{
	t_list		*dict;
	const char	*fname = "numbers.dict";
	char		*n;

	if (argc == 1)
		n = ft_push(trimzeros(ft_strtrim(get_next_line(0), "\n")));
	else
		n = ft_push(trimzeros(argv[argc - 1]));
	if (!checkargs(argc, n))
	{
		ft_putendl_fd("Error", 2);
		return (ft_return(E_ARGS));
	}
	if (argc == 3)
		fname = argv[1];
	if (!parsedict(fname, &dict) || !checkdict(ft_strdup(n), dict))
	{
		ft_putendl_fd("Dict Error", 2);
		return (ft_return(E_DICT));
	}
	if (ft_atou64(n))
		print(n, dict);
	else
		ft_putendl_fd(dict_getentry(dict, 0), 1);
	return (ft_return(0));
}

static uint8_t	checkargs(int16_t argc, char *n)
{
	if (argc > 3)
		return (0);
	return (checknbr(n));
}

static uint8_t	checknbr(char *n)
{
	if (!n)
		return (0);
	if (!ft_atou64(n) && !ft_strequals(n , "0"))
		return (0);
	while (*n)
	{
		if (!ft_isdigit(*n++))
			return (0);
	}
	return (1);
}

static char		*trimzeros(char *n)
{
	if (!n)
		return (NULL);
	while (ft_isspace(*n))
		n++;
	if (!ft_isdigit(*n) && *n != '+')
		return (NULL);
	while (*n == '0' && n[1])
		n++;
	return (ft_strdup(n));
}
