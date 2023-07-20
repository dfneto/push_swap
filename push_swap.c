
#include "push_swap.h"



//int	main(int argc, char *argv[])
int	main()
{
	int argc = 4;
	char *argv[] = {"0", "1", "2", "3"};
//	if (argc > 1)
//	{
		//TODO: check errors

		t_list *first = ft_lstnew(atoi(argv[1]));
		t_list *node;

		int i = 2;
		while(i <= (argc - 1))
		{
			node = ft_lstnew(atoi(argv[i++]));
			ft_lstadd_back(&first, node);
		}
		print_list(first, argc - 1);
		//printf("O endereço de root eh     : %p\n", root);
		//printf("First aponta para o endeço: %p\n", first);
		swap(&first);
		//printf("First aponta para o endeço: %p\n", first);
		print_list(first, argc - 1);
//		printf("list size = %d\n", ft_lstsize(root));
//		print_list(root, argc - 1);
		
//	}
	//free no
	return (0);
}
