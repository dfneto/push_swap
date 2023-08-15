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

int	get_len_list(t_list *root)
{
	int	i;

	i = 0;
	if (root == NULL)
		return (0);
	while (root)
	{
		root = root->next;
		i++;
	}
	return (i);
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

int	calculate_index_distance(t_list *root, int index_desired)
{
	int	index_distance;
	int	len;

	index_distance = 0;
	len = get_len_list(root);
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
