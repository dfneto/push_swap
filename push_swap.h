#include <stdio.h>

typedef struct s_list
{
//	void 			*content;
	int				value;
	struct s_list	*next;
}	t_list;

#include <stdlib.h>
#include <unistd.h>
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *root);
t_list	*get_prev_last(t_list *root);
void	ft_lstadd_back(t_list **first, t_list *new);
void	print_list(t_list *root, int len_list);
int		ft_lstsize(t_list *lst);




void	swap(t_list **first, char c);
void	rotate(t_list **first, char c);
void	reverse_rotate(t_list **first, char c);
void	push(t_list **first_a, t_list **first_b, char c);
void	double_swap(t_list **first_a, t_list **first_b);
void	double_rotate(t_list **first_a, t_list **first_b);
void	double_reverse_rotate(t_list **first_a, t_list **first_b);
