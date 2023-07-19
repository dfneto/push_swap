#include "push_swap.h"

void	swap(t_list **first)
{
	t_list	*temp;

	temp = *first;
	*first = first->next;
	first->next = temp;
}
