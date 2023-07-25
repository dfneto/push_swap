#include "push_swap.h"


//TODO: faço o bubble sorte e depois outro algorito que use as duas pilhas para entender como funciona o uso dos movimentos e para usar os programas de gráficos e 
// de ver em quanto tempo meu algoritmo resolve o problema. Depois estudar um pouco sobre complexidade
void	bubble_sort(t_list **first, int len) 
{
	t_list	*a;
	t_list	*temp;

	a = *first;
	while(len - 1 > 0)
	{
		if(a->value > a->next->value)
		{
			temp = a->next;				   // aqui estou alterando para onde a seta/ponteiro temp aponta, ou seja, altero o endereço que temp armazena
			a->next = a->next->next; // aqui estou alterando para onde a seta/ponteiro next aponta, ou seja, o endereco que armazena next 
			temp->next = a;
			//*first = temp;
		}
		else
			a = a->next;
		len--;
	}
	print_list(*first, ft_lstsize(*first));
}

void	bubble_sort_linked_list(t_list **first)//TODO: entender esse bubble sorte: fazer no caderno
{
	t_list *head = *first;
	t_list *current;
	t_list *prev;
	t_list *next_node;

	if (head == NULL || head->next == NULL)
		return;
	
	int sorted = 0;
	while(!sorted)
	{
		sorted = 1;
		current = head;
		prev = NULL;

		while (current->next)
		{
			next_node = current->next;
			if (current->value > next_node->value) //swap the nodes
			{
				if (prev) //se existe um nó prev é porque estamos no meio da lista ...
					prev->next = next_node; 
				else //... se não existe é porque estamos no início da lista
					head = next_node;

				current->next = next_node->next;
				next_node->next = current;
				prev = next_node;
				sorted = 0;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
	}
	*first = head;
}





