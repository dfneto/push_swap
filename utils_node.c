/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:07:48 by davifern          #+#    #+#             */
/*   Updated: 2023/08/10 20:07:49 by davifern         ###   ########.fr       */
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
