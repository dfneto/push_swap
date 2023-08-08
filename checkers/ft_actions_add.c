/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:06:51 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/07 12:11:08 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_act_swaps(t_node **lst_a, t_node **lst_b, int op)
{
	ft_mov_swap(lst_b);
	ft_mov_swap(lst_a);
	if (write(1, "ss\n", 3))
		return (0);
}

int	ft_act_rotates(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	ft_mov_rot(lst_a, st_a);
	ft_mov_rot(lst_b, st_b);
	if (write(1, "rr\n", 3))
		return (0);
}

int	ft_act_revrots(t_node **lst_a, t_node **lst_b, t_stack *st_a, t_stack *st_b)
{
	ft_mov_revrot(lst_a, st_a);
	ft_mov_revrot(lst_b, st_b);
	if (write(1, "rrr\n", 4))
		return (0);
}
