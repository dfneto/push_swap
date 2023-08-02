#include "push_swap.h"

int	list_is_ordered(t_list *first)
{
	while(first->next)
	{
		if(first->value < first->next->value)
			first = first->next;
		else
			return 0;
	}
	return 1;
}

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
	print_list(*first);
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
	print_list(first);
}

//TODO: aqui devo receber um **first porque vou alterar o first
//void	sort_3_numbers(char *argv[])
void	sort_3_numbers(t_list **first, t_list *second, t_list *third)
{
	/*t_list *first = ft_lstnew(atoi(argv[1]));
	t_list *second = ft_lstnew(atoi(argv[2]));
	t_list *third = ft_lstnew(atoi(argv[3]));
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
	*/
	if(list_is_ordered(*first))
		exit(0);
	if ((*first)->value > second->value && second->value < third->value && third->value > (*first)->value) //2 1 3
		swap(first, 'a');
	else if ((*first)->value > second->value && second->value > third->value && third->value < (*first)->value) //3 2 1
	{
		swap(first, 'a');
		reverse_rotate(first, 'a');
	}
	else if ((*first)->value > second->value && second->value < third->value && third->value < (*first)->value) //3 1 2
		rotate(first, 'a');
	else if ((*first)->value < second->value && second->value > third->value && third->value > (*first)->value) //1 3 2
	{
		swap(first, 'a');
		rotate(first, 'a');
	}
	else if ((*first)->value < second->value && second->value > third->value && third->value < (*first)->value) //2 3 1
		reverse_rotate(first, 'a');
	//print_list(*first);
}

int	get_min_value(t_list *node)
{
	int min_value = node->value;
	node = node->next;

	while(node)
	{
		if (node->value < min_value)
			min_value = node->value;
		node = node->next;
	}
	return (node->index);
}
//TODO: refazer de uma forma mais simples
void	set_the_index_to_the_list(t_list *first, int len)
{
	t_list		*node;
	t_list		*current;
	int			prev_value;
	int			index;

	if (!first)
		return; //TODO verificar se estou tratando corretamente o caso de node = null
	index = 0;
	prev_value = -2147483648;
	while (index < len)
	{
		node = first;
		while (node)
		{
			if (node->value > prev_value)
			{
				current = node;
				break;
			}
			node = node->next;
		}
		node = first;
		while (node)
		{
			if (node->value < current->value && node->value > prev_value)
				current = node;
			node = node->next;
		}
		current->index = index;
		index++;
		prev_value = current->value;
	}
	// print_list(first);
}

// void	push_the_min_value_to_list_b(t_list **first, t_list **first_b)
// {
// 	int min_value = get_min_value(*first);

// 	while ((*first)->value != min_value) //primeira posicao
// 	{
// 		if ((*first)->next->value == min_value) //segunda posicao
// 			swap(first, 'a');
// 		else if ((*first)->next->next->value == min_value) //terceira posicao
// 			rotate(first, 'a');
// 		else //quarta e quinta posicao
// 			reverse_rotate(first, 'a');
// 	}
// 	push(first, first_b, 'b');
// }

int	get_min_index(t_list *node)
{
	int min_index = node->index;
	while(node)
	{
		if (node->index < min_index)
			min_index = node->index;
		node = node->next;
	}
	return min_index;
}

void	push_the_min_value_to_list_b(t_list **first, t_list **first_b)
{
	int min_index = get_min_index(*first); //TODO: acho que posso fazer hard code a posicao 0 e 1 porque sempre vao ser os dois menores indices
	if((*first)->index != min_index) //primeira posição
	{
		if((*first)->next->index == min_index) //segunda posicao
			swap(first, 'a');
		else if((*first)->next->next->index == min_index) //terceira posicao
			rotate(first, 'a');
		else //quarta e quinta posicao
			reverse_rotate(first, 'a');
	}
	if (list_is_ordered(*first)) //aqui first é um **, se eu passsar somente first estou passando um **, então tenho que passar somente um nó que é *
		exit(0);
	push(first, first_b, 'b');
}

void	sort_5_numbers(char *argv[], int len)
{
	t_list *first = ft_lstnew(atoi(argv[1])); //aqui first é um nó, ou seja, um ponteiro para uma estrutura t_list, ou seja, armazena o endereço da t_list.
	t_list *first_b = NULL;
	t_list *node;

	int i = 2;
	while(i <= len)
	{
		node = ft_lstnew(atoi(argv[i++]));
		ft_lstadd_back(&first, node);
	}
	
	//TODO: se eu receber 5 1 2 3 4 vou fazer um monte de movimentos quando só deveria fazer um rotate. 
	//Talvez deva antes de fazer 5 movimentos (5 eh o minimo de movimentos que vou fazer quando só tenho um número fora de ordem), 
	//posso antes tentar ordenar com até 4 movimento e se conseguir não prossigo.
	// Mas tbm isso pode ser o mesmo que testar muitas possibilidades e escolher a melhor o que no final vou também gastar processamento.
	if (list_is_ordered(first)) 
		exit(0);
	set_the_index_to_the_list(first, len);
	push_the_min_value_to_list_b(&first, &first_b);
	if (len == 5)
		push_the_min_value_to_list_b(&first, &first_b);
	sort_3_numbers(&first, first->next, first->next->next);	
	push(&first_b, &first, 'a');
	push(&first_b, &first, 'a');

	// print_list(first);
}

void	sort_up_to_100_numbers(char *argv[], int len)
{
	t_list *first = ft_lstnew(atoi(argv[1]));
	t_list *first_b = NULL;
	t_list *node;
	int	chunk = 0;

	int i = 2;
	while(i <= len)
	{
		node = ft_lstnew(atoi(argv[i++]));
		ft_lstadd_back(&first, node);
	}
	if (list_is_ordered(first)) 
		exit(0);
	set_the_index_to_the_list(first, len);


	//envio os elementos de A para B em chunks
	while(first) //quando first = null nao tem mais elementos em A
	{
		i = 0;
		len = get_len_list(first);
		chunk = chunk + 3;
		while(i < len)
		{
			node = first;
			if (node->index < chunk)
			{
				// node = node->next;
				push(&first, &first_b, 'b');
			}
			else
			{
				// node = node->next;
				rotate(&first, 'a');
			}
			i++;
		}
	}

	int index_desired = get_len_list(first_b) - 1;
	
	while(first_b)
	{	//se o topo da stack é o indice que procuro faco push
		if(first_b->index == index_desired || first_b->index == index_desired - 1) 
		{
			push(&first_b, &first, 'a'); //TODO: fazer swap em A ...
			index_desired--;
			continue;
		}
		//se o top não é o indice, vou procurar o caminho mais curto para fazer o rotate ou reverse-rotate
		i = 0;
		node = first_b;
		while(i <= index_desired)										
		{
			if(node->index == index_desired)
			{
				if (i < index_desired / 2) //faco rotate ate encontrar o elemento e deixar ele no topo da stack de b. E se encontro o len-1 faco um push
				{
					node = first_b;
					while(node->index != index_desired)//o nó não eh o elemento que procuro
					{
						if (node->index == index_desired - 1)
							push(&first_b, &first, 'a');
						rotate(&first_b, 'b');
						node = node->next;
					}
				}
				else //faco rr ate encontrar o elemento e deixar ele no topo da stack de b. E se encontro o len-1 faco um push
				{
					node = first_b;
					while(node->index != index_desired)//o nó não eh o elemento que procuro
					{
						if (node->index == index_desired - 1)
							push(&first_b, &first, 'a');
						reverse_rotate(&first_b, 'b');
						node = node->next;
					}
				}
				continue; //sair deste while
			}
			else
			{
				node = node->next;
				i++;
			}
		}



	}

	print_list(first_b);
}