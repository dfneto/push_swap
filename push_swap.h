#include <stdio.h>

typedef struct s_list
{
//	void 			*content;
	int				value;
	struct s_list	*next;
}	t_list;

#include <stdlib.h>
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *root);
void	ft_lstadd_back(t_list **first, t_list *new);
void	print_list(t_list *root, int len_list);
int		ft_lstsize(t_list *lst);




void	swap(t_list **first);