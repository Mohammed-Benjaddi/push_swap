/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_new_stack_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:37:44 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 15:37:45 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	swap_stack_a_b(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->length < 2)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
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
