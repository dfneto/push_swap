#include "push_swap.h"

void	swap(t_list **first, char c)
{
	t_list	*temp;

	temp = *first; //enquanto **first é um ponteiro de um ponteiro, *first é um ponteiro e temp tbm, ambos para um nó, ou seja, *first e temp são ponteiros que guardam o endereço de uma estrutura t_list, mas poderia ser de um int ou char -> jogar no python tutor pra ver como ele coloca o endereço que temp tem no first.
	*first = (*first)->next; //somente first (sem *) é um ponteiro de um ponteiro, *first eh um ponteiro para um nó, ou seja, um nó. Assim estou alterando o nó para o qual *first aponta
	temp->next = (*first)->next; //temp->next eh um ponteiro, (*first)->next tbm eh um ponteiro. Entao estou dizendo que ambos ponteiros apontam para (armazenam a) mesma direção
	(*first)->next = temp;
	temp = NULL;
	free(temp); //TODO: ver no python tutor pq acho que nao faz diferença isso
	if (c)
		printf("s%c\n", c);
}

void	rotate(t_list **first, char c)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*first);
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

	last = ft_lstlast(*first);
	prev_last = get_prev_last(*first);
	last->next = *first; 
	*first = last;
	prev_last->next = NULL;
	if (c)
		printf("rr%c\n", c);
}

void	push(t_list **first_a, t_list **first_b, char c)
{
	t_list	*temp;

	temp = *first_a;
	*first_a = (*first_a)->next;
	temp->next = *first_b;
	*first_b = temp;
	if (c)
		printf("p%c\n", c);
}

void	double_swap(t_list **first_a, t_list **first_b)
{
	swap(first_a, 'a');
	swap(first_b, 'b');
}

void	double_rotate(t_list **first_a, t_list **first_b)
{
	rotate(first_a, 'a');
	rotate(first_b, 'b');
}

void	double_reverse_rotate(t_list **first_a, t_list **first_b)
{
	reverse_rotate(first_a, 'a');
	reverse_rotate(first_b, 'b');
}




