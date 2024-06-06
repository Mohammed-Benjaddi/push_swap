/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:10:18 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/18 16:49:47 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack)
{
	if (stack->length <= 3)
		ft_sort_three(stack);
	else if (stack->length <= 5)
		ft_sort_five(stack);
	else if (stack->length <= 100)
		ft_range_sort(stack, 0, 15);
	else
		ft_range_sort(stack, 0, 35);
}
