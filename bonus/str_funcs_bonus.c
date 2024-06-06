/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funcs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:37:55 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 15:37:57 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	if (!s1)
		return (NULL);
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n)
	{
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	if (i == n)
		return ((int)(*(unsigned char *)(s1 + i - 1) - *(unsigned char *)(s2 + i
					- 1)));
	return ((int)(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}

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

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
