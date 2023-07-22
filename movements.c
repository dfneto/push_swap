#include "push_swap.h"

void	swap(t_list **first, char a_b)
{
	t_list	*temp;
	char	*str;

	temp = *first;
	*first = (*first)->next;
	temp->next = (*first)->next;
	(*first)->next = temp;
	free(temp);
	if (a_b == 'a')
		str = "sa\n\0";  //verificar: 'write' doesn't expect null-terminated strings (chat)
	else
		str = "sb\n\0";
	write(1, str, 4);
}
	/*minha versao primeira versão (funciona):
	t_list *temp;
	temp = (*first)->next; //temp eh um ponteiro, (*first)->next tbm eh um ponteiro. Entao estou dizendo que ambos ponteiros apontam para (armazenam a) mesma direção
	(*first)->next = temp->next;
	temp->next = *first;
	//first = &temp; //o errado aqui é que estou pegando o endereço de temp, quando o que eu quero eh o valor de temp, ou seja, para quem ele aponta que eh o endereço do segundo nó, como fiz em *first = temp;
	*first = temp; // enquanto **first é um ponteiro de um ponteiro, *first é um ponteiro e temp tbm
	*/

void	rotate(t_list **first, char a_b)
{
	//TODO
}
