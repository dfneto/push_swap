#include "push_swap.h"


//TODO: façø o bubble sorte e depois outro algorito que use as duas pilhas para entender como funciona o uso dos movimentos e para usar os programas de gráficos e de ver em quanto tempo meu algoritmo resolve o problema. Depois estudar um pouco sobre complexidade
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
