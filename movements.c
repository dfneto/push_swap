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
	*first = temp; // enquanto **first é um ponteiro de um ponteiro, *first é um ponteiro e temp tbm, ambos para um nó, ou seja, *first e temp são ponteiros que guardam o endereço de uma estrutura t_list, mas poderia ser de um int ou char
	*/

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
	last->next = *first; //somente first é um ponteiro de um ponteiro, *first eh o ponteiro de um nó, ou seja, um nó
	*first = last;
	prev_last->next = NULL;
	if (c)
		printf("rr%c\n", c);
}
