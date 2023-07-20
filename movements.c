#include "push_swap.h"

void	swap(t_list **first)
{
	t_list	*temp;
	temp = (*first)->next;
	(*first)->next = temp->next;
	temp->next = (*first);
	*first = temp; 	

	//minha versao:
	/*
	t_list	*temp;
	temp = (*first)->next;
	temp->next = *first;
	(*first)->next = temp->next;
	first = &temp; */
	
	/* versao do chat
	t_list *temp = *first;
    *first = (*first)->next;
    temp->next = (*first)->next;
    (*first)->next = temp;
	*/
}
