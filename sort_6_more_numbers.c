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
 * Reorder the stack accordingly with the index of the nodes 
 * (first, second and last) and the desired index. By the end
 * the stack will be orderded in the best way to receive the 
 * numbers from b.
 * first if: index_desired - first index == 2 (let the third in 
 * the last position)
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
* The original version was in the method sort_6_more_numbers and was:
* push(&first_b, &first, 'a'); 
* reorder_stack_a(&first, index_desired);
* index_desired = get_max_index(first_b);
* index_distance = 0;
*/
void	push_node_into_a_and_recalculate_next_index_desired(t_list **first,
		t_list **first_b, int *index_distance, int *index_desired)
{
	push(first_b, first, 'a'); 
	reorder_stack_a(first, *index_desired);
	*index_desired = get_max_index(*first_b);
	*index_distance = 0;
}

/*
* The original version was in the method sort_6_more_numbers and was:
* if (!index_distance)
* 	index_distance = calculate_index_distance(first_b, index_desired);
* len = get_len_list(first_b);
* if (index_distance < len / 2)
* 	rotate(&first_b, 'b');
* else
*	reverse_rotate(&first_b, 'b');
*/
void	rotate_or_reverse_rotate(t_list **first_b, int *index_distance,
		int index_desired)
{
	int	len;

	len = 0;
	if (!*index_distance)
		*index_distance = 
			calculate_index_distance(*first_b, index_desired);
	len = get_len_list(*first_b);
	if (*index_distance < len / 2)
		rotate(first_b, 'b');
	else
		reverse_rotate(first_b, 'b');
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

	first_b = NULL;
	if (list_is_ordered(first)) 
		return ;
	push_all_nodes_to_b_by_chunks(&first, &first_b);
	index_desired = len - 1;
	index_distance = 0;
	while (first_b)
	{
		if (first_b->index == index_desired
			|| first_b->index == index_desired - 1
			|| first_b->index == index_desired - 2)
			push_node_into_a_and_recalculate_next_index_desired(&first,
				&first_b, &index_distance, &index_desired);
		else
			rotate_or_reverse_rotate(&first_b, &index_distance, index_desired);
	}
	free_list(first);
	first = NULL;
	first_b = NULL;
}
