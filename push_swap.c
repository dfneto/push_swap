#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"



int	main(int argc, char *argv[])
{
	//criar uma lista de nós com a entrada
	t_node node;
	t_node node1;

	if (argc > 1)
	{
		node0.value = atoi(argv[1]);
		node1.value = atoi(argv[2]);
		node0.next = &node1;
		printf("%d\n", node0.value);
		printf("%d\n", node0.next->value);
	}

	t_list root = ft_lstnew(argv[2]);
	t_list *first = root;
	t_list no;
	int i = 3;
	while(i < (argc - 2))
	{
		no = ft_lstnew(argv[i]);
		ft_lstadd_back(&first, no);
	}
	//free no
	return (0);
}
