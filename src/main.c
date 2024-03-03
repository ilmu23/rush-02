/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:08:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 17:02:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	t_list		*dict;
	const char	*fname = "numbers.dict";

	if ((argc != 2 && argc != 3)
		|| (!ft_atou64(argv[argc - 1])
			&& !ft_strequals("0", argv[argc - 1])))
	{
		ft_putendl_fd("Error", 2);
		return (ft_return(E_ARGS));
	}
	if (argc == 3)
		fname = argv[1];
	if (!parsedict(fname, &dict))
	{
		ft_putendl_fd("Dict Error", 2);
		return (ft_return(E_DICT));
	}
	print(argv[argc - 1], dict);
	return (ft_return(0));
}
