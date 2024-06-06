/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_new_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:09:53 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 13:33:57 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_new_stack(int arr_length)
{
	t_stack	*current;

	current = malloc(sizeof(t_stack));
	if (!current)
		return (NULL);
	current->length = 0;
	current->array = malloc(sizeof(int) * arr_length);
	if (!current->array)
		return (NULL);
	return (current);
}

void	swap_stack_a_b(t_stack *a, t_stack *b, char *flag)
{
	swap_stack(a, NULL);
	swap_stack(b, NULL);
	if (flag)
		check_flag(flag);
}

void	swap_stack(t_stack *stack, char *flag)
{
	int	temp;

	if (stack->length < 2)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	if (flag)
		check_flag(flag);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack *b)
{
	free(b->array);
	free(b);
	b = NULL;
}
