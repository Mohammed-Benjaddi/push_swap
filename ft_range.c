/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:46 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/06 13:29:50 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_nums(int *src, int size)
{
	int	i;
	int	*dst;

	i = 0;
	dst = malloc(sizeof(int) * size);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

static int	*simple_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	*sorted_arr;

	i = 0;
	j = 0;
	sorted_arr = copy_nums(arr, size);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_arr[i] > sorted_arr[j])
			{
				temp = sorted_arr[i];
				sorted_arr[i] = sorted_arr[j];
				sorted_arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted_arr);
}

static void	push_to_stack_a(t_stack *a, t_stack *b)
{
	int	i;
	int	index_max;

	i = 0;
	while (b->length)
	{
		index_max = find_index(b->array, b->length, ft_max(b));
		if (index_max <= (b->length / 2))
		{
			while (index_max--)
				rotate_stack(b, "rb");
		}
		else
		{
			while (b->length - index_max++ != 0)
				rotate_rev_stack(b, "rrb");
		}
		push_stack(b, a, "pa");
	}
}

static void	push_to_stack_b(t_stack *a, t_stack *b, int *start, int *end)
{
	if (a->index >= *start && a->index <= *end)
	{
		push_stack(a, b, "pb");
		*start += 1;
		*end += 1;
	}
	else if (a->index < *start)
	{
		push_stack(a, b, "pb");
		rotate_stack(b, "rb");
		*start += 1;
		*end += 1;
	}
	else
		rotate_stack(a, "ra");
}

void	ft_range_sort(t_stack *a, int start, int end)
{
	t_stack	*b;
	int		*sorted_arr;
	int		sorted_len;

	sorted_arr = simple_sort(a->array, a->length);
	b = initialize_new_stack(a->length);
	sorted_len = a->length;
	while (a->length)
	{
		a->index = find_index(sorted_arr, sorted_len, a->array[0]);
		push_to_stack_b(a, b, &start, &end);
	}
	push_to_stack_a(a, b);
	free(sorted_arr);
	ft_free(b);
}
