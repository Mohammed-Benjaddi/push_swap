/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:24 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/17 20:55:16 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int				i;
	unsigned int	slen;
	char			*res;

	i = 0;
	slen = (unsigned int)ft_strlen(s);
	if (!s || start > slen)
		return (ft_strdup(""));
	if (len > (int)slen || (len < (int)slen && len + (int)start > (int)slen))
		len = (int)slen - (int)start;
	res = (char *)malloc(sizeof(char) * (len) + 1);
	if (res == NULL)
		return (NULL);
	while (i < (int)len && s[start + i] != '\0')
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
