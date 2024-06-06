/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:48:36 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/20 21:04:25 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	if (!*s1 && s2)
		return (ft_strdup(s2));
	if (*s1 && !s2)
		return (ft_strdup(*s1));
	if (!*s1 && !s2)
		return (NULL);
	res = (char *)malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, *s1, s1_len + 1);
	ft_strlcpy(res + s1_len, s2, s1_len + s2_len + 1);
	free(*s1);
	s1 = NULL;
	return (res);
}
