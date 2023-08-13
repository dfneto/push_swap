/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:32:15 by davifern          #+#    #+#             */
/*   Updated: 2023/08/10 19:33:10 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

int		has_errors(int len, char *argv[]);
void    free_list(t_list *first);
t_list	*create_node(int value);
t_list	*get_last_node(t_list *root);
t_list	*get_prev_last(t_list *root);
void	add_node_back(t_list **first, t_list *new);
int		get_len_list(t_list *root);
int		list_is_ordered(t_list *first);
void	print_list(t_list *root);
void	swap(t_list **first, char c);
void	rotate(t_list **first, char c);
void	reverse_rotate(t_list **first, char c);
void	push(t_list **first_src, t_list **first_dst, char c);
void	set_the_index_to_the_list(t_list *first, int len);
int		get_min_index(t_list *node);
void	sort_2_numbers(char *argv[]);
void	sort_3_numbers(char *argv[]);
void	sort_3_nodes(t_list **first, t_list *secod, t_list *third);
void	sort_5_numbers(char *argv[], int len);
void	sort_6_more_numbers(char *argv[], int len);
