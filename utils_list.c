/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:33:09 by davifern          #+#    #+#             */
/*   Updated: 2023/08/14 16:11:12 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len_list(t_list *root)
{
	int	i;

	i = 0;
	if (root == NULL)
		return (0);
	while (root)
	{
		root = root->next;
		i++;
	}
	return (i);
}

int	list_is_ordered(t_list *first)
{
	while (first->next)
	{
		if (first->value < first->next->value)
			first = first->next;
		else
			return (0);
	}
	return (1);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	is_repeated(int value, t_list *first)
{
	while (first)
	{
		if (first->value == value)
			return (1);
		first = first->next;
	}
	return (0);
}

t_list	*create_unique_list(char *argv[], int len)
{
	int		i;
	int		index_distance;
	int		value;
	t_list	*first;
	t_list	*node;

	index_distance = 0;
	first = create_node(ft_atoi(argv[1]));
	i = 2;
	while (i <= len)
	{
		value = atoi(argv[i++]);
		if (is_repeated(value, first))
			return (0);
		node = create_node(value);
		add_node_back(&first, node);
	}
	node = NULL;
	set_the_index_to_the_list(first, len);
	return (first);
}

/*
void	print_list(t_list *root)
{
	int	i;
	int	len;

	i = 0;
	len = get_len_list(root);
	printf("id\tvalue\n");
	while (i < len)
	{
		printf("%d\t%d\n", root->index, root->value);
		root = root->next;
		i++;
	}
}
*/
