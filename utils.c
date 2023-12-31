/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:34:05 by davifern          #+#    #+#             */
/*   Updated: 2023/08/15 15:54:03 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	atoll(const char *str)
{
	long long	result;
	int			i;
	int			signal;

	result = 0;
	signal = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * signal);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	signal;

	result = 0;
	signal = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * signal);
}

int	is_number(char *c)
{
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	while (*c)
	{
		if (*c < 48 || *c > 57)
			return (0);
		c++;
	}
	return (1);
}

int	has_errors(char *argv[])
{
	int			i;
	long long	num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		num = atoll(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}
