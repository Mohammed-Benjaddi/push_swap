/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:10:59 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/18 10:17:12 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_symbols(char *str, char **res)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
	{
		free_args(res);
		ft_error();
	}
	if (((str[i] != '+' && str[i] != '-') && !ft_isdigit(str[i]))
		|| ft_isalpha(str[i]))
	{
		free_args(res);
		ft_error();
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			free_args(res);
			ft_error();
		}
		i++;
	}
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

int	find_index(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
