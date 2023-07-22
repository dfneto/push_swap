#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*ret;
	
	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

//  a.out		#1			#2
//argv[0]		argv[1]		argv[2]
//arc=1			argc=2		arc=3
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	last->next = new;
}

void	print_list(t_list *root, int len_list)
{
	int	i;

	i = 0;
	while(i < len_list)
	{
		printf("Node value = %d - %p\n", root->value, root);
		root = root->next;
		i++;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
