/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:17:43 by davifern          #+#    #+#             */
/*   Updated: 2023/08/10 19:17:44 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *first;

	first = NULL;
	if (argc > 1)
	{
		if (has_errors(argc - 1, argv))
			return (0);
		
		if (argc == 3)
			sort_2_numbers(argv);
		if (argc == 4)
			sort_3_numbers(argv);
		if (argc == 5 || argc == 6)
			sort_5_numbers(argv, argc - 1);
		if (argc > 6)
			sort_6_more_numbers(argv, argc - 1);
	}
	return (0);
}
