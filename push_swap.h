/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:32:15 by davifern          #+#    #+#             */
/*   Updated: 2023/08/14 15:28:26 by davifern         ###   ########.fr       */
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

int		has_errors(char *argv[]);
int		ft_atoi(const char *str);
void	free_list(t_list *first);
t_list	*create_unique_list(char *argv[], int len);
t_list	*create_node(int value);
t_list	*get_last_node(t_list *root);
t_list	*get_prev_last(t_list *root);
void	add_node_back(t_list **first, t_list *new);
int		get_len_list(t_list *root);
int		list_is_ordered(t_list *first);
void	swap(t_list **first, char c);
void	rotate(t_list **first, char c);
void	reverse_rotate(t_list **first, char c);
void	push(t_list **first_src, t_list **first_dst, char c);
void	set_the_index_to_the_list(t_list *first, int len);
int		get_min_value(t_list *node);
int		get_chunk_size(int len);
int		get_max_index(t_list *first);
int		calculate_index_distance(t_list *root, int index_desired);
void	sort_2_numbers(t_list *first);
void	sort_3_numbers(t_list *first);
void	sort_3_nodes(t_list **first, t_list *secod, t_list *third);
void	sort_5_numbers(t_list *first, int len);
void	sort_6_more_numbers(t_list *first, int len);
void	push_all_nodes_to_b_by_chunks(t_list **first, t_list **first_b);
