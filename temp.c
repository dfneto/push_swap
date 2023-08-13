/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:51:08 by davifern          #+#    #+#             */
/*   Updated: 2023/08/13 17:51:09 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_repeated(int value)
{
    (void) value;
    return (0);
}
int create_unique_list(char *argv[], int len)
{   
    int     i;
    int     index_distance;
    int     value;
    t_list  *first;
    t_list  *node;

    index_distance = 0;
	first = create_node(atoi(argv[1]));
	i = 2;
	while (i <= len)
	{
        value = atoi(argv[i++]);
        if (is_repeated(value))
            return (0);
		node = create_node(value);
		add_node_back(&first, node);
	}
    //free(node)
    node = NULL;
    set_the_index_to_the_list(first, len);
    return (1);
}

int has_errors2(char *argv[], int len)
{
    if(!create_unique_list(argv, len))
        return (1);
    (void) argv;
    return (0);
}
