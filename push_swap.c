
#include "push_swap.h"

//TODO: check errors
//TODO: use my ft_printf
int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		//if (argc == 2) nao faca nada porque so tem um no
		if (argc == 3) //para 2 numberos
			sort_2_numbers(argv);
		if (argc == 4) // para 3 numeros
			sort_3_numbers(argv);
		if (argc == 5 || argc == 6) // para 4 ou 5 numeros
			sort_3_numbers(argv);
		t_list *first = ft_lstnew(atoi(argv[1])); //aqui first é um nó, ou seja, um ponteiro para uma estrutura t_list, ou seja, armazena o endereço da t_list.
//		t_list *first_b = NULL;
		t_list *node;

		int i = 2;
		while(i <= (argc - 1))
		{
			node = ft_lstnew(atoi(argv[i++]));
			ft_lstadd_back(&first, node);
		}
		node = NULL; 
		free(node);

//		swap(&first, 'a');
//		rotate(&first, 'a');
//		reverse_rotate(&first, 'a');
//		push(&first, &first_b, 'b');
//		double_swap(&first, &first_b);
//		double_rotate(&first, &first_b);
//		double_reverse_rotate(&first, &first_b);
//		print_list(first, ft_lstsize(first));
//		printf("first value = %d, add = %p\n\n", first->value, first);
//		bubble_sort_linked_list(&first);
//		print_list(first, ft_lstsize(first));
	}
	return (0);
}
