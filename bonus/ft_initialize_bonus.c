/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:09:38 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 11:27:47 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_digit(char *nums)
{
	int		j;
	char	**res;

	res = ft_split(nums, ' ');
	j = 0;
	while (res[j])
	{
		check_symbols(res[j], res);
		j++;
	}
	free_args(res);
	return (j);
}

static int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	count_numbers(char **nums)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (nums[i] != NULL)
	{
		if (ft_is_space(nums[i]))
			ft_error();
		counter += check_digit(nums[i]);
		i++;
	}
	return (counter);
}

static void	add_to_arr(long long int num, t_stack **stack, char **res)
{
	t_stack	*current;
	int		number;

	if (num < INT_MIN || num > INT_MAX)
	{
		ft_free(*stack);
		free_args(res);
		ft_error();
	}
	number = num;
	current = *stack;
	if (is_exist(number, *stack))
	{
		ft_free(*stack);
		free_args(res);
		ft_error();
	}
	current->array[current->length] = number;
	current->length += 1;
}

t_stack	*ft_initialize(char **numbers, int size)
{
	t_stack	*current;
	int		i;
	int		j;
	char	**nums;
	int		arr_len;

	if (!(size - 1))
		exit(0);
	i = 1;
	arr_len = count_numbers(numbers);
	current = initialize_new_stack(arr_len);
	if (!current)
		return (NULL);
	while (numbers[i])
	{
		j = 0;
		nums = ft_split(numbers[i], ' ');
		while (nums[j])
			add_to_arr(ft_atoi(nums[j++]), &current, nums);
		i++;
		free_args(nums);
	}
	return (current);
}
