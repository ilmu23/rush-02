/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/02/26 12:52:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front.c
 */

#include "libft.h"

/** @brief Adds a new node to the front of a list
 *
 * Adds a new node to the list, initializing the list size
 * if the list is empty
 * @param **list Address of the head pointer to the list
 * @param *node Address of the new node
 */
void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (!list || !node)
		return ;
	ft_lstpush(node);
	if (!*list)
	{
		node->size = ft_push(ft_calloc(1, sizeof(size_t)));
		if (!node->size)
			return ;
	}
	else
	{
		node->size = (*list)->size;
		(*list)->prev = node;
		node->next = *list;
	}
	*list = node;
	(*node->size)++;
}
