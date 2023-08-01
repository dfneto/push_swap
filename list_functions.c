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

void	print_list(t_list *root)
{
	int	i;
	int len;

	i = 0;
	len = get_len_list(root);
	while(i < len)
	{
		printf("Id/Value %d - %d\n", root->index, root->value);
		root = root->next;
		i++;
	}
}
/*
void	print_lists(t_list *root_a, t_list *root_b)
{
	int	i;
	int	len_a;
	int	len_b;
	int	higher_len;
	char a = '_';
	char b = '_';

	i = 0;
	len_a = get_len_list(root_a);
	len_b = get_len_list(root_b);
	if (len_a > len_b)
		higher_len = len_a;
	else
		higher_len = len_b;
	printf("List A\t\t\tList B\n");
	while(i < higher_len)
	{
		if (root_a->value)
			a = root_a->value + 48;
		if (root_b->value)
			b = root_b->value + 48;
		printf("%c\t\t\t%c\n", a, b);
		root_a = root_a->next;
		root_b = root_b->next;
		a = '_';
		b = '_';
		i++;
	}
}
*/
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
