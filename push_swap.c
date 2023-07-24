
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
		print_list(first, argc - 1);
		printf("Nó de first: %p\n", first);
		swap(&first, 'a');
		printf("Depois do swap ...\n");
		printf("Nó de first: %p\n", first);
		print_list(first, argc - 1);
		swap(&first, 'b');
		printf("Depois do swap ...\n");
		printf("Nó de first: %p\n", first);
		print_list(first, argc - 1); //TODO: entender pq depois do segundo swap da ruim
		
	}
	//free no
	return (0);
}
