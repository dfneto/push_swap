#include "push_swap.h"

void	swap(t_list **first, char c)
{
	t_list	*temp;

	temp = *first;
	*first = (*first)->next;
	temp->next = (*first)->next;
	(*first)->next = temp;
	temp = NULL;
	free(temp); //TODO: ver no python tutor pq acho que nao faz diferença isso
	if (c)
		printf("s%c\n", c);
}
	/*minha versao primeira versão (funciona):
	t_list *temp;
	temp = (*first)->next; //temp eh um ponteiro, (*first)->next tbm eh um ponteiro. Entao estou dizendo que ambos ponteiros apontam para (armazenam a) mesma direção
	(*first)->next = temp->next;
	temp->next = *first;
	//first = &temp; //o errado aqui é que estou pegando o endereço de temp, quando o que eu quero eh o valor de temp, ou seja, para quem ele aponta que eh o endereço do segundo nó, como fiz em *first = temp;
	*first = temp; // enquanto **first é um ponteiro de um ponteiro, *first é um ponteiro e temp tbm
	*/

void	rotate(t_list **first, char c)
{
	t_list	*last;
	t_list	*prev_last;

	last = ft_lstlast(*first);
	prev_last = get_prev_last(*first);
	last->next = *first;
	prev_last->next = NULL;
	*first = last;
	last = NULL; //TODO: remover essas limpezas se nao faz diferença
	prev_last = NULL;
	free(last);
	free(prev_last);
	if (c)
		printf("r%c\n", c);
	//printf("o prev last valor: %d\n", prev_last->value);
	/*
	a->b->c->null
	b->c->a->null
	*/

}
