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
	int half_chunk;

	while(*first) //quando first = null nao tem mais elementos em A
	{
		i = 0;
		len = get_len_list(*first);
		chunk = chunk + chunk_size;
		half_chunk = (chunk + (chunk - chunk_size))/ 2;
		while(i < len)
		{
			node = *first;
			if (node->index <= chunk)
			{
				push(first, first_b, 'b');
				if (node->index <= half_chunk)
					rotate(first_b, 'b');
			}
			else
				rotate(first, 'a');
			i++;
		}
	}
}

int	calculate_index_distance(t_list *root, int index_desired, int len)
{
	int	index_distance;

	index_distance = 0;
	while(index_distance < len)
	{
		if(root->index == index_desired)
			return (index_distance);
		else
			root = root->next;
		index_distance++;
	}
	return (index_distance);
}

void	reorder_stack_a(t_list **first, int index_desired)
{
	if(index_desired - (*first)->index == 2)
		rotate(first, 'a');
	if((*first)->next && (*first)->index == index_desired && (*first)->index - (*first)->next->index == 1)
		swap(first, 'a');
	t_list *temp = get_last_node(*first);
	if((*first)->index - temp->index == 1 || (*first)->index - get_last_node(*first)->index == 2)
		reverse_rotate(first, 'a');
}

int	get_max_index(t_list *first)
{
	int	max_index;

	max_index = 0;
	while(first)
	{
		if(first->index > max_index)
			max_index = first->index;
		first = first->next;
	}
	return (max_index);
}

void	sort_6_more_numbers(char *argv[], int len)
{
	t_list *first = create_node(atoi(argv[1]));
	t_list *first_b = NULL;
	t_list *node;
	int	index_desired;
	int	index_distance = 0;

	int i = 2;
	while(i <= len)
	{
		node = create_node(atoi(argv[i++]));
		add_node_back(&first, node);
	}
	if (list_is_ordered(first)) 
		exit(0);
	set_the_index_to_the_list(first, len);

	push_all_nodes_to_b_by_chunks(&first, &first_b);

	index_desired = len - 1; //começa do maior ao menor
	while(first_b)
	{	//se o topo da stack é o indice que procuro faco push
		if(first_b->index == index_desired || first_b->index == index_desired - 1 || first_b->index == index_desired - 2)
		{
			push(&first_b, &first, 'a'); 
			reorder_stack_a(&first, index_desired);
			index_desired = get_max_index(first_b);
			
			// if(first->next && first->index > first->next->index)  //se na stack A tem um número menor em baixo do maior, faco um swap
			// {
			// 	swap(&first, 'a');
			// 	index_desired--;
			// }
			// index_desired--;
			
		}//TODO: acrescentar no if abaixo se o no atual eh o indice_desired -2 tbm
		// else if (first_b->index == index_desired - 1 || first_b->index == index_desired - 2) //se o top da stack é o índice anterior que procuro envio para a stack A 
			// push(&first_b, &first, 'a'); //se eu fiz um push de um número menor, o próximo index_desired não vai estar em B, mas em A
		else
		{
			if (!index_distance)
				index_distance = calculate_index_distance(first_b, index_desired, len);
			if (index_distance < index_desired / 2) 
				rotate(&first_b, 'b');
			else
				reverse_rotate(&first_b, 'b');
		}
	}
	// printf("Lista A:\n");
	// print_list(first);
	// printf("----------------:\n");
	// printf("Lista B:\n");
	// print_list(first_b);
}