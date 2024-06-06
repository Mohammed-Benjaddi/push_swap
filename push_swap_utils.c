/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:56:01 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 15:12:55 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = stack->array[0];
	while (i < stack->length)
	{
		if (max < stack->array[i])
			max = stack->array[i];
		i++;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = stack->array[0];
	while (i < stack->length)
	{
		if (min > stack->array[i])
			min = stack->array[i];
		i++;
	}
	return (min);
}

bool	is_sorted(t_stack *stack)
{
	int	i;
	int	*arr;

	i = 0;
	arr = stack->array;
	while (i < stack->length - 1)
	{
		if (arr[i] > arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	check_flag(char *flag)
{
	if (!ft_strncmp(flag, "sa", ft_strlen(flag)))
		ft_putstr_fd("sa\n", 1);
	else if (!ft_strncmp(flag, "sb", ft_strlen(flag)))
		ft_putstr_fd("sb\n", 1);
	else if (!ft_strncmp(flag, "ss", ft_strlen(flag)))
		ft_putstr_fd("ss\n", 1);
	else if (!ft_strncmp(flag, "pa", ft_strlen(flag)))
		ft_putstr_fd("pa\n", 1);
	else if (!ft_strncmp(flag, "pb", ft_strlen(flag)))
		ft_putstr_fd("pb\n", 1);
	else if (!ft_strncmp(flag, "ra", ft_strlen(flag)))
		ft_putstr_fd("ra\n", 1);
	else if (!ft_strncmp(flag, "rb", ft_strlen(flag)))
		ft_putstr_fd("rb\n", 1);
	else if (!ft_strncmp(flag, "rr", ft_strlen(flag)))
		ft_putstr_fd("rr\n", 1);
	else if (!ft_strncmp(flag, "rra", ft_strlen(flag)))
		ft_putstr_fd("rra\n", 1);
	else if (!ft_strncmp(flag, "rrb", ft_strlen(flag)))
		ft_putstr_fd("rrb\n", 1);
	else if (!ft_strncmp(flag, "rrr", ft_strlen(flag)))
		ft_putstr_fd("rrr\n", 1);
}
