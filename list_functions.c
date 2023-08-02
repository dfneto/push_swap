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

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*get_prev_last(t_list *root)
{
	while(root->next->next != NULL)
		root = root->next;
	return (root);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	last->next = new;
}

int	get_len_list(t_list *root)
{
	int i;

	i = 0;
	if (root == NULL)
		return (0);
	while(root)
	{
		root = root->next;
		i++;
	}
	return (i);	
}

int	list_is_ordered(t_list *first)
{
	while(first->next)
	{
		if(first->value < first->next->value)
			first = first->next;
		else
			return 0;
	}
	return 1;
}

void	print_list(t_list *root)
{
	int	i;
	int len;

	i = 0;
	len = get_len_list(root);
	printf("id\tvalue\n");
	while(i < len)
	{
		printf("%d\t%d\n", root->index, root->value);
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
