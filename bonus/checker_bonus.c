/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:14:04 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 11:15:08 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	excute_operations(t_stack *a, t_stack *b, char *instraction)
{
	if (!ft_strcmp(instraction, "sa"))
		swap_stack(a);
	else if (!ft_strcmp(instraction, "sb"))
		swap_stack(b);
	else if (!ft_strcmp(instraction, "ss"))
		swap_stack_a_b(a, b);
	else if (!ft_strcmp(instraction, "pa"))
		push_stack(b, a);
	else if (!ft_strcmp(instraction, "pb"))
		push_stack(a, b);
	else if (!ft_strcmp(instraction, "ra"))
		rotate_stack(a);
	else if (!ft_strcmp(instraction, "rb"))
		rotate_stack(b);
	else if (!ft_strcmp(instraction, "rr"))
		rotate_a_b(a, b);
	else if (!ft_strcmp(instraction, "rra"))
		rotate_rev_stack(a);
	else if (!ft_strcmp(instraction, "rrb"))
		rotate_rev_stack(b);
	else if (!ft_strcmp(instraction, "rrr"))
		rotate_rev_a_b(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize(av, ac);
	b = initialize_new_stack(a->length);
	ft_apply_instructions(a, b);
	if (is_sorted(a) && !b->length)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(a);
	ft_free(b);
	return (0);
}
