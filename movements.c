/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:51:35 by davifern          #+#    #+#             */
/*   Updated: 2023/08/08 15:51:36 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **first, char c)
{
	t_list	*temp;

	temp = *first; //enquanto **first é um ponteiro de um ponteiro, *first é um ponteiro e temp tbm, ambos para um nó, ou seja, *first e temp são ponteiros que guardam o endereço de uma estrutura t_list, mas poderia ser de um int ou char -> jogar no python tutor pra ver como ele coloca o endereço que temp tem no first.
	*first = (*first)->next; //somente first (sem *) é um ponteiro de um ponteiro, *first eh um ponteiro para um nó, ou seja, um nó. Assim estou alterando o nó para o qual *first aponta
	temp->next = (*first)->next; //temp->next eh um ponteiro, (*first)->next tbm eh um ponteiro. Entao estou dizendo que ambos ponteiros apontam para (armazenam a) mesma direção
	(*first)->next = temp;
	temp = NULL;
	free(temp); //TODO: ver no python tutor pq acho que nao faz diferença isso - ver se tem leaks
	if (c)
		printf("s%c\n", c);
}

void	rotate(t_list **first, char c)
{
	t_list	*last;
	t_list	*temp;

	last = get_last_node(*first);
	temp = *first;
	last->next = *first;
	*first = (*first)->next;
	temp->next = NULL;
	if (c)
		printf("r%c\n", c);
}

void	reverse_rotate(t_list **first, char c)
{
	t_list	*last;
	t_list	*prev_last;

	last = get_last_node(*first);
	prev_last = get_prev_last(*first);
	last->next = *first; 
	*first = last;
	prev_last->next = NULL;
	if (c)
		printf("rr%c\n", c);
}

void	push(t_list **first_src, t_list **first_dst, char c)
{
	t_list	*temp;

	temp = *first_src;
	*first_src = (*first_src)->next;
	temp->next = *first_dst;
	*first_dst = temp;
	if (c)
		printf("p%c\n", c);
}

/*
void	double_swap(t_list **first_src, t_list **first_dst)
{
	swap(first_src, 'a');
	swap(first_dst, 'b');
}

void	double_rotate(t_list **first_src, t_list **first_dst)
{
	rotate(first_src, 'a');
	rotate(first_dst, 'b');
}

void	double_reverse_rotate(t_list **first_src, t_list **first_dst)
{
	reverse_rotate(first_src, 'a');
	reverse_rotate(first_dst, 'b');
}
*/
