#include "push_swap.h"

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

int	get_chunk_size(int len)
{
	if (len <= 100)
		return 20;
	else
		return 62;
}

/*
void	push_all_nodes_to_b_by_chunks(t_list **first, t_list **first_b)
{
	t_list *node;
	int i;
	int	chunk = 0;
	int len = get_len_list(*first);
	int chunk_size = get_chunk_size(len);

	while(*first) //quando first = null nao tem mais elementos em A
	{
		i = 0;
		len = get_len_list(*first);
		chunk = chunk + chunk_size;
		while(i < len)
		{
			node = *first;
			if (node->index < chunk)
				push(first, first_b, 'b');
			else
				rotate(first, 'a');
			i++;
		}
	}
}
*/

void	push_all_nodes_to_b_by_chunks(t_list **first, t_list **first_b)
{
	t_list *node;
	int i;
	int	chunk = 0;
	int len = get_len_list(*first);
	int chunk_size = get_chunk_size(len);

	while(*first) //quando first = null nao tem mais elementos em A
	{
		i = 0;
		len = get_len_list(*first);
		chunk = chunk + chunk_size;
		while(i < len)
		{
			node = *first;
			if (node->index <= chunk)
			{
				push(first, first_b, 'b');
				if (node->index <= (chunk / 2))
					rotate(first_b, 'b');
			}
			else
				rotate(first, 'a');
			i++;
		}
	}
}

void	sort_6_more_numbers(char *argv[], int len)
{
	t_list *first = ft_lstnew(atoi(argv[1]));
	t_list *first_b = NULL;
	t_list *node;
	int	index_desired;

	int i = 2;
	while(i <= len)
	{
		node = ft_lstnew(atoi(argv[i++]));
		ft_lstadd_back(&first, node);
	}
	if (list_is_ordered(first)) 
		exit(0);
	set_the_index_to_the_list(first, len);

	push_all_nodes_to_b_by_chunks(&first, &first_b);

	index_desired = --len; //começa do maior ao menor
	while(first_b)
	{	//se o topo da stack é o indice que procuro faco push
		if(first_b->index == index_desired)
		{
			push(&first_b, &first, 'a'); 
			if(first->next && first->index > first->next->index)  //se na stack A tem um número menor em baixo do maior, faco um swap
			{
				swap(&first, 'a');
				index_desired--;	
			}	
			index_desired--;
			continue;
		}//TODO: acrescentar no if abaixo se o no atual eh o indice_desired -2 tbm
		else if (first_b->index == index_desired - 1) //se o top da stack é o índice anterior que procuro envio para a stack A 
		{
			push(&first_b, &first, 'a'); //se eu fiz um push de um número menor, o próximo index_desired não vai estar em B, mas em A
			continue;
		}
		//se o top não é o indice, vou procurar o caminho mais curto para fazer o rotate ou reverse-rotate
		i = 0; //i vai me dizer quantos nós têm acima do nó com o index procurado
		node = first_b;
		while(i <= index_desired) //TODO: verificar se node eh nulo em todos os casos que uso node e que nao fiz isso antes (para evitar repetir codigo)										
		{
			if(node && node->index == index_desired) //se o no tem o índice procurado
			{
				node = first_b;
				if (i <= index_desired / 2) //faco rotate ate encontrar o elemento e deixar ele no topo da stack de b. E se encontro o len-1 faco um push
				{
					while(node && node->index != index_desired)//o nó não eh o elemento que procuro
					{
						if (node->index == (index_desired - 1))  //acrescentar no if abaixo se o no atual eh o indice_desired -2 tbm
							push(&first_b, &first, 'a');
						node = node->next;
						rotate(&first_b, 'b');
					}
				}
				else //faco rr ate encontrar o elemento e deixar ele no topo da stack de b. E se encontro o len-1 faco um push
				{
					while(node->index != index_desired)//o nó não eh o elemento que procuro
					{	
						if (node->index == index_desired - 1) //acrescentar no if abaixo se o no atual eh o indice_desired -2 tbm
							push(&first_b, &first, 'a');
						reverse_rotate(&first_b, 'b');
						node = first_b;
					}
				}
				break; //sair deste while
			}
			else //se o no não tem o índice procurado
			{
				if (node)
					node = node->next; //var para o próximo nó
				i++;
			}
		}
	}
	printf("Lista A:\n");
	print_list(first);
	printf("----------------:\n");
	printf("Lista B:\n");
	print_list(first_b);
}