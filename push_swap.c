/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:17:43 by davifern          #+#    #+#             */
/*   Updated: 2023/08/15 15:54:53 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*first;

	first = NULL;
	if (argc > 1)
	{
		if (has_errors(argv))
			return (print_error());
		first = create_unique_list(argv, argc - 1);
		if (first == NULL)
			return (print_error());
		if (argc == 3)
			sort_2_numbers(first);
		if (argc == 4)
			sort_3_numbers(first);
		if (argc == 5 || argc == 6)
			sort_5_numbers(first, argc - 1);
		if (argc > 6)
			sort_6_more_numbers(first, argc - 1);
	}
	return (0);
}
