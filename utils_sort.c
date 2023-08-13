/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:12:53 by davifern          #+#    #+#             */
/*   Updated: 2023/08/13 16:11:18 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_the_index_to_the_list(t_list *first, int len)
{
	int		index;
	long	previous_min;
	t_list	*min_node;
	t_list	*aux_node;

	index = 0;
	previous_min = -2147483649;
	while (index < len)
	{
		min_node = first;
		aux_node = first->next;
		while (aux_node)
		{
			if ((aux_node->value < min_node->value 
					&& aux_node->value > previous_min) 
				|| min_node->value <= previous_min)
				min_node = aux_node;
			aux_node = aux_node->next;
		}
		min_node->index = index;
		previous_min = min_node->value;
		index++;
	}
}

int	get_min_value(t_list *node)
{
	int	min_value;

	min_value = node->value;
	node = node->next;
	while (node)
	{
		if (node->value < min_value)
			min_value = node->value;
		node = node->next;
	}
	return (node->index);
}

int	get_chunk_size(int len)
{
	if (len <= 100)
		return (20);
	else
		return (62);
}

int	get_max_index(t_list *first)
{
	int	max_index;

	max_index = 0;
	while (first)
	{
		if (first->index > max_index)
			max_index = first->index;
		first = first->next;
	}
	return (max_index);
}

int	calculate_index_distance(t_list *root, int index_desired, int len)
{
	int	index_distance;

	index_distance = 0;
	while (index_distance < len)
	{
		if (root->index == index_desired)
			return (index_distance);
		else
			root = root->next;
		index_distance++;
	}
	return (index_distance);
}
