/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:07:48 by davifern          #+#    #+#             */
/*   Updated: 2023/08/10 20:07:49 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

t_list	*get_last_node(t_list *first)
{
	while (first != NULL && first->next != NULL)
		first = first->next;
	return (first);
}

t_list	*get_prev_last(t_list *first)
{
	while (first->next->next != NULL)
		first = first->next;
	return (first);
}

void	add_node_back(t_list **first, t_list *new)
{
	t_list	*last;

	if (!(*first) || !new)
		return ;
	last = get_last_node(*first);
	last->next = new;
	last = NULL;
}
