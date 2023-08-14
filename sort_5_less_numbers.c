/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_less_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:50:48 by davifern          #+#    #+#             */
/*   Updated: 2023/08/13 17:42:50 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
while((*first)->index != min_index) //primeira posição
{
	if((*first)->next->index == min_index) //segunda posicao
	else if((*first)->next->next->index == min_index) //terceira posicao
	else //quarta e quinta posicao
}
Abaixo first é um **. Se eu passsar somente first estou passando um **,
então tenho que passar somente um nó que é *
if (list_is_ordered(*first)) 
*/
void	push_the_min_index_to_list_b(t_list **first,
		t_list **first_b, int min_index)
{
	while ((*first)->index != min_index)
	{
		if ((*first)->next->index == min_index)
			swap(first, 'a');
		else if ((*first)->next->next->index == min_index)
			rotate(first, 'a');
		else
			reverse_rotate(first, 'a');
	}
	push(first, first_b, 'b');
}

/*
* Eu poderia colocar o first = NULL dentro do free_list como fez Aitor, 
* mas ia tornar o metodo free list mais complicado e menos legivel
*/
void	sort_2_numbers(t_list *first)
{
	if (first->value > first->next->value)
		swap(&first, 'a');
	free_list(first);
	first = NULL;
}

/* To sort 3 nodes I test all possibilities and for each one I aplly the
 * right ones to sort then in each if else condition
 * if 		... 2 1 3
 * else if	... 3 2 1
 * else if	... 3 1 2
 * else if	... 1 3 2
 * else if	... 2 3 1
 */
void	sort_3_nodes(t_list **first, t_list *second, t_list *third)
{
	if (list_is_ordered(*first))
		return ;
	if ((*first)->value > second->value && second->value < third->value && 
		third->value > (*first)->value)
		swap(first, 'a');
	else if ((*first)->value > second->value && second->value > third->value && 
		third->value < (*first)->value)
	{
		swap(first, 'a');
		reverse_rotate(first, 'a');
	}
	else if ((*first)->value > second->value && second->value < third->value && 
		third->value < (*first)->value)
		rotate(first, 'a');
	else if ((*first)->value < second->value && second->value > third->value && 
		third->value > (*first)->value)
	{
		swap(first, 'a');
		rotate(first, 'a');
	}
	else if ((*first)->value < second->value && second->value > third->value && 
		third->value < (*first)->value)
		reverse_rotate(first, 'a');
}

void	sort_5_numbers(t_list *first, int len)
{
	t_list	*first_b;

	first_b = NULL;
	if (list_is_ordered(first)) 
		return ;
	push_the_min_index_to_list_b(&first, &first_b, 0);
	if (len == 5)
		push_the_min_index_to_list_b(&first, &first_b, 1);
	sort_3_nodes(&first, first->next, first->next->next);
	push(&first_b, &first, 'a');
	if (len == 5)
		push(&first_b, &first, 'a');
	free_list(first);
	first = NULL;
	first_b = NULL;
}

void	sort_3_numbers(t_list *first)
{
	sort_3_nodes(&first, first->next, first->next->next);
	free_list(first);
	first = NULL;
}
