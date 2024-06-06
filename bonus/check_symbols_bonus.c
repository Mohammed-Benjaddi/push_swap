/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:22:00 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 13:38:58 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
