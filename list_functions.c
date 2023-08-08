/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:33:09 by davifern          #+#    #+#             */
/*   Updated: 2023/08/08 15:34:42 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

t_list	*get_last_node(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*get_prev_last(t_list *root)
{
	while (root->next->next != NULL)
		root = root->next;
	return (root);
}

void	add_node_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = get_last_node(*lst);
	last->next = new;
}

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
