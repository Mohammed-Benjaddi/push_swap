/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:11:07 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/05 20:17:16 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_stack *stack)
{
	if (stack->array[0] > stack->array[1])
		swap_stack(stack, "sa");
}

static void	two_moves(t_stack *stack)
{
	if (stack->array[0] > stack->array[1] && stack->array[1] > stack->array[2]
		&& stack->array[2] < stack->array[0])
	{
		swap_stack(stack, "sa");
		rotate_rev_stack(stack, "rra");
	}
	else if (stack->array[0] < stack->array[1]
		&& stack->array[1] > stack->array[2]
		&& stack->array[2] > stack->array[0])
	{
		swap_stack(stack, "sa");
		rotate_stack(stack, "ra");
	}
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->length <= 2)
		ft_sort_two(stack);
	else
	{
		if (stack->array[0] > stack->array[1]
			&& stack->array[1] < stack->array[2]
			&& stack->array[2] > stack->array[0])
			swap_stack(stack, "sa");
		else if (stack->array[0] > stack->array[1]
			&& stack->array[1] < stack->array[2]
			&& stack->array[2] < stack->array[0])
			rotate_stack(stack, "ra");
		else if (stack->array[0] < stack->array[1]
			&& stack->array[1] > stack->array[2]
			&& stack->array[2] < stack->array[0])
			rotate_rev_stack(stack, "rra");
		else
			two_moves(stack);
	}
}
