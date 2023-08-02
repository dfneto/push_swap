#include <stdio.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

#include <stdlib.h>
#include <unistd.h>
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *root);
t_list	*get_prev_last(t_list *root);
void	ft_lstadd_back(t_list **first, t_list *new);
void	print_list(t_list *root);
void	print_lists(t_list *root_a, t_list *root_b);
int		ft_lstsize(t_list *lst);
int	get_len_list(t_list *root);



void	swap(t_list **first, char c);
void	rotate(t_list **first, char c);
void	reverse_rotate(t_list **first, char c);
void	push(t_list **first_src, t_list **first_dst, char c);
void	double_swap(t_list **first_src, t_list **first_dst);
void	double_rotate(t_list **first_src, t_list **first_dst);
void	double_reverse_rotate(t_list **first_src, t_list **first_dst);


void	bubble_sort(t_list **first, int len);
void	bubble_sort_linked_list(t_list **first);
void    sort_2_numbers(char *argv[]);
//void    sort_3_numbers(char *argv[]);
void    sort_3_numbers(t_list **first, t_list *secod, t_list *third);
void    sort_5_numbers(char *argv[], int len);
void	sort_up_to_100_numbers(char *argv[], int len);

