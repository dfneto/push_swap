
#include "push_swap.h"



int	main(int argc, char *argv[])
//int	main()
{
//	int argc = 4;
//	char *argv[] = {"0", "1", "2", "3"};
	if (argc > 1)
	{
		//TODO: check errors
		//TODO: use my ft_printf

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
		print_list(first, ft_lstsize(first));
		bubble_sort(&first, ft_lstsize(first));
	}
	return (0);
}
