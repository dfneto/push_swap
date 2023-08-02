#include "push_swap.h"

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

