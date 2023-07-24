#include "push_swap.h"


void	bubble_sort(t_list **first, int len)
{
	t_list	*a;
	t_list	*temp;

	a = *first;
	while(len > 0)
	{
		while(a->next)
		{
			if(a->value > a->next->value)
			{
				temp = a;
				a = a->next;
				temp->next = temp;
			}
			else
				a = a->next;
		}
		len--;
	}
	print_list(*first, ft_lstsize(*first));
}
