/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:20:30 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 15:34:10 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if ((!s1 && s2) || (s1 && !s2))
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static int	check_move(char *move)
{
	if (!move)
		return (0);
	if (!ft_strcmp(move, "pa\n") || !ft_strcmp(move, "pb\n") || !ft_strcmp(move,
			"ra\n") || !ft_strcmp(move, "rra\n") || !ft_strcmp(move, "rb\n")
		|| !ft_strcmp(move, "rrb\n") || !ft_strcmp(move, "rr\n")
		|| !ft_strcmp(move, "rrr\n") || !ft_strcmp(move, "sb\n")
		|| !ft_strcmp(move, "sa\n") || !ft_strcmp(move, "ss\n"))
		return (1);
	return (0);
}

static void	free_all_and_exit(t_stack *a, t_stack *b, char *buff, char *result)
{
	free(buff);
	ft_free(a);
	ft_free(b);
	free(result);
	ft_error();
}

static char	**get_instructions(t_stack *a, t_stack *b)
{
	char	*buff;
	char	*result;
	int		i;
	char	**instractions;

	i = 0;
	result = NULL;
	while (1)
	{
		buff = get_next_line(0);
		if (buff == NULL)
			break ;
		if (!check_move(buff))
			free_all_and_exit(a, b, buff, result);
		result = ft_strjoin(&result, buff);
		free(buff);
	}
	instractions = ft_split(result, '\n');
	free(result);
	result = NULL;
	return (instractions);
}

void	ft_apply_instructions(t_stack *a, t_stack *b)
{
	char	**instructions;
	int		i;

	i = 0;
	instructions = get_instructions(a, b);
	if (!instructions)
	{
		free_args(instructions);
		return ;
	}
	while (instructions[i])
		excute_operations(a, b, instructions[i++]);
	free_args(instructions);
}
