/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:09:58 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 11:29:13 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *from, t_stack *to, char *flag)
{
	int	i;
	int	temp;

	if (!from->length)
		return ;
	temp = from->array[0];
	i = 0;
	while (i < from->length - 1)
	{
		from->array[i] = from->array[i + 1];
		i++;
	}
	from->length--;
	i = to->length;
	while (i > 0)
	{
		to->array[i] = to->array[i - 1];
		i--;
	}
	to->array[i] = temp;
	to->length++;
	if (flag)
		check_flag(flag);
}

void	rotate_rev_stack(t_stack *stack, char *flag)
{
	int	temp;
	int	i;

	i = stack->length - 1;
	if (stack->length > 1)
	{
		temp = stack->array[stack->length - 1];
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = temp;
	}
	if (flag)
		check_flag(flag);
}

void	rotate_stack(t_stack *stack, char *flag)
{
	int	temp;
	int	i;

	i = 0;
	if (stack->length > 1)
	{
		temp = stack->array[0];
		while (i < stack->length - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->length - 1] = temp;
	}
	if (flag)
		check_flag(flag);
}

void	rotate_rev_a_b(t_stack *stack_a, t_stack *stack_b, char *flag)
{
	rotate_rev_stack(stack_a, NULL);
	rotate_rev_stack(stack_b, NULL);
	if (flag)
		check_flag(flag);
}

void	rotate_a_b(t_stack *stack_a, t_stack *stack_b, char *flag)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	if (flag)
		check_flag(flag);
}
