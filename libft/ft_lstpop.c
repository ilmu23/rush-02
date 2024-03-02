/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:10:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:38:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpop
 */

#include "libft.h"

/** @brief Pops the node and its content
 *
 * @param *node Address of the node
 * @retval t_list* Address of the node
 */
t_list	*ft_lstpop(t_list *node)
{
	ft_popblk(node);
	ft_popblk(node->blk);
	return (node);
}
