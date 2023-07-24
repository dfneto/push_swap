
#include "push_swap.h"



int	main(int argc, char *argv[])
//int	main()
{
//	int argc = 4;
//	char *argv[] = {"0", "1", "2", "3"};
	if (argc > 1)
	{
		//TODO: check errors

		t_list *first = ft_lstnew(atoi(argv[1]));
		t_list *node;

		int i = 2;
		while(i <= (argc - 1))
		{
			node = ft_lstnew(atoi(argv[i++]));
			ft_lstadd_back(&first, node);
		}
		node = NULL; 
		free(node);
		//swap(&first, 'a');
		print_list(first, argc - 1); 
//		rotate(&first, 'a');
		reverse_rotate(&first, 'a');
		print_list(first, argc - 1); 
		
	}
	return (0);
}
