/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:21:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/02 15:44:06 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_atou64(const char *s)
{
	uint64_t	out;

	out = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		if (out > UINT64_MAX / 10 || (out == UINT64_MAX / 10 && *s > '5'))
			return (0);
		out = out * 10 + (*s - '0');
		s++;
	}
	return (out);
}
