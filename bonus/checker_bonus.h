/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:00 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 15:34:33 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int			length;
	int			*array;
}				t_stack;

void			ft_apply_instructions(t_stack *a, t_stack *b);
char			*get_next_line(int fd);
int				ft_strchr_gnl(char *s, char c);
void			ft_strlcat_gnl(char *dst, char *src);
void			ft_strlcpy_gnl(char *dst, char *src);
void			excute_operations(t_stack *a, t_stack *b, char *instraction);
int				ft_strcmp(char *s1, char *s2);
t_stack			*ft_initialize(char **numbers, int size);
void			ft_putstr_fd(char *str, int fd);
t_stack			*initialize_new_stack(int arr_length);
void			swap_stack_a_b(t_stack *a, t_stack *b);
void			swap_stack(t_stack *stack);
void			ft_error(void);
void			push_stack(t_stack *from, t_stack *to);
void			rotate_rev_stack(t_stack *stack);
void			rotate_stack(t_stack *stack);
void			rotate_rev_a_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_a_b(t_stack *stack_a, t_stack *stack_b);
void			ft_free(t_stack *b);
bool			is_sorted(t_stack *stack);
void			free_args(char **nums);
int				is_exist(int number, t_stack *stack);
char			*ft_strjoin(char **s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strlen(const char *s);
void			check_symbols(char *str, char **res);
long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_substr(char const *s, unsigned int start, int len);

#endif
