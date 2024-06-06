/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:56:01 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 15:25:36 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	free_args(char **nums)
{
	int	i;

	i = 0;
	if (!nums)
		return ;
	while (nums[i])
		free(nums[i++]);
	free(nums);
	nums = NULL;
}

int	is_exist(int number, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->length)
	{
		if (stack->array[i] == number)
			return (1);
		i++;
	}
	return (0);
}
