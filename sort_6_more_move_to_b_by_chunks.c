/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_more_move_to_b_by_chunks.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:54:20 by davifern          #+#    #+#             */
/*   Updated: 2023/08/15 15:54:24 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* The original version was in the method push_all_nodes_to_b_by_chunks
* inside of while (i < len) and was:
* node = *first;
* if (node->index <= chunk)
* {
*   push(first, first_b, 'b');
*   if (node->index <= half_chunk)
*       rotate(first_b, 'b');
* }
* else
*   rotate(first, 'a');
* i++;
*/
void	push_node_in_the_top_or_bottom_half_of_b(t_list **first,
		t_list **first_b, int chunk, int half_chunk)
{
	t_list	*node;

	node = *first;
	if (node->index <= chunk)
	{
		push(first, first_b, 'b');
		if (node->index <= half_chunk)
			rotate(first_b, 'b');
	}
	else
		rotate(first, 'a');
}

/*
* while(*first) ... //quando first = null nao tem mais elementos em A
*/
void	push_all_nodes_to_b_by_chunks(t_list **first, t_list **first_b)
{
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
			push_node_in_the_top_or_bottom_half_of_b(first,
				first_b, chunk, half_chunk);
			i++;
		}
	}
}
