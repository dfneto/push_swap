/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_more_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:04:42 by davifern          #+#    #+#             */
/*   Updated: 2023/08/14 15:29:44 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* while(*first) //quando first = null nao tem mais elementos em A
*/
void	push_all_nodes_to_b_by_chunks(t_list **first, t_list **first_b)
{
	t_list	*node;
	int		i;
	int		chunk;
	int		len; 
	int		chunk_size;
	int		half_chunk;

	len = get_len_list(*first);
	chunk_size = get_chunk_size(len);
	chunk = 0;
	while (*first)
	{
		i = 0;
		len = get_len_list(*first);
		chunk = chunk + chunk_size;
		half_chunk = (chunk + (chunk - chunk_size)) / 2;
		while (i < len)
		{
			node = *first;
			if (node->index <= chunk)
			{
				push(first, first_b, 'b');
				if (node->index <= half_chunk)
					rotate(first_b, 'b');
			}
			else
				rotate(first, 'a');
			i++;
		}
	}
}

/*
 * Reorder the stack accordingly with the index of the nodes 
 * (first, second and last) and the desired index
 * first if: index_desired - first index == 2
 * second if: first index == desired && index_desired - second index = 1
 * third if: second index == index_desired && index_desired - last index == 2
 */
void	reorder_stack_a(t_list **first, int index_desired)
{
	if (index_desired - (*first)->index == 2)
		rotate(first, 'a');
	if ((*first)->next && (*first)->index == index_desired
		&& index_desired - (*first)->next->index == 1)
		swap(first, 'a');
	if ((*first)->next && (((*first)->next->index == index_desired 
				&& (*first)->index - get_last_node(*first)->index == 1) || 
			((*first)->index == index_desired 
				&& index_desired - get_last_node(*first)->index == 2)))
		reverse_rotate(first, 'a');
}

/*
 * We start to look for the index desired from the last to
 * the first one: index_desired = len - 1;
 */
void	sort_6_more_numbers(t_list *first, int len)
{
	t_list	*first_b;
	int		index_desired;
	int		index_distance;

	index_distance = 0;
	first_b = NULL;
	if (list_is_ordered(first)) 
		return ;
	push_all_nodes_to_b_by_chunks(&first, &first_b);
	index_desired = len - 1;
	while (first_b)
	{
		// function(&first, &first_b, &index_desired);
		if (first_b->index == index_desired
			|| first_b->index == index_desired - 1
			|| first_b->index == index_desired - 2)
		{
			push(&first_b, &first, 'a'); 
			reorder_stack_a(&first, index_desired);
			index_desired = get_max_index(first_b);
			index_distance = 0;
		}
		else
		{
			if (!index_distance)
				index_distance = 
					calculate_index_distance(first_b, index_desired, len); //TODO: por que len nao muda? entendo que se faço um push o len muda, mas eu nao recalculo
			if (index_distance < index_desired / 2) 
				rotate(&first_b, 'b');
			else
				reverse_rotate(&first_b, 'b');
		}
	}
	free_list(first);
	first = NULL;
	first_b = NULL;
}
