/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:11:32 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/06 13:30:54 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_correct_pos(t_stack *stack, int num)
{
	int	i;
	int	target;

	i = 0;
	target = 2147483647;
	while (i < stack->length)
	{
		if (target > stack->array[i] && num < stack->array[i])
			target = stack->array[i];
		i++;
	}
	if (target == 2147483647)
		target = ft_min(stack);
	return (find_index(stack->array, stack->length, target));
}

static void	ft_push_to_a(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->length > 0)
	{
		pos = find_correct_pos(a, b->array[0]);
		if (pos <= (a->length / 2))
		{
			while (pos-- != 0)
				rotate_stack(a, "ra");
		}
		else
		{
			while (a->length - pos++ != 0)
				rotate_rev_stack(a, "rra");
		}
		push_stack(b, a, "pa");
	}
}

static void	re_arrange_stack(t_stack *stack)
{
	int	i;
	int	min;
	int	index_min;

	i = 0;
	min = ft_min(stack);
	index_min = find_index(stack->array, stack->length, min);
	if (index_min >= 0 && index_min <= (stack->length / 2))
	{
		while (index_min--)
			rotate_stack(stack, "ra");
	}
	else
	{
		while (stack->length - index_min++ != 0)
			rotate_rev_stack(stack, "rra");
	}
}

void	ft_sort_five(t_stack *a)
{
	t_stack	*b;
	int		i;

	i = 0;
	b = initialize_new_stack(a->length);
	while (a->length - 3 != 0)
		push_stack(a, b, "pb");
	ft_sort_three(a);
	ft_push_to_a(a, b);
	re_arrange_stack(a);
	ft_free(b);
}
