
#include "push_swap.h"



int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		//TODO: check errors

		t_list *root = ft_lstnew(atoi(argv[1]));
		t_list *first = root;
		t_list *node;

		int i = 2;
		while(i <= (argc - 1))
		{
			node = ft_lstnew(atoi(argv[i++]));
			ft_lstadd_back(&first, node);
		}
		swap(&first);
//		printf("list size = %d\n", ft_lstsize(root));
//		print_list(root, argc - 1);
		
	}
	//free no
	return (0);
}
