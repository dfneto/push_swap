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

void	sort_2_numbers(char *argv[])
{
	t_list *first = ft_lstnew(atoi(argv[1]));
	t_list *second = ft_lstnew(atoi(argv[2]));
	ft_lstadd_back(&first, second);

	if (first->value > second->value)
		swap(&first, 'a');
	print_list(first, 2);
}

void	sort_3_numbers(char *argv[])
{
	t_list *first = ft_lstnew(atoi(argv[1]));
	t_list *second = ft_lstnew(atoi(argv[2]));
	t_list *third = ft_lstnew(atoi(argv[3]));
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
	
	if (first->value > second->value && second->value < third->value && third->value > first->value) //2 1 3
		swap(&first, 'a');
	else if (first->value > second->value && second->value > third->value && third->value < first->value) //3 2 1
	{
		swap(&first, 'a');
		reverse_rotate(&first, 'a');
	}
	else if (first->value > second->value && second->value < third->value && third->value < first->value) //3 1 2
		rotate(&first, 'a');
	else if (first->value < second->value && second->value > third->value && third->value > first->value) //1 3 2
	{
		swap(&first, 'a');
		rotate(&first, 'a');
	}
	else //2 3 1
		reverse_rotate(&first, 'a');
	print_list(first,3);
}

void	sort_5_numbers(char *argv[])
{
//TODO: 1 5 2 4 6 -> do this case!
}
