/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:57:28 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/21 11:51:14 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int			length;
	int			*array;
	int			index;
}				t_stack;

t_stack			*initialize_new_stack(int arr_length);
t_stack			*ft_initialize(char **numbers, int size);
void			ft_sort(t_stack *stack);
void			ft_sort_three(t_stack *stack);
void			ft_range_sort(t_stack *stack, int start, int end);
void			ft_sort_five(t_stack *a);
void			push_stack(t_stack *from, t_stack *to, char *flag);
void			swap_stack(t_stack *stack, char *flag);
void			swap_stack_a_b(t_stack *a, t_stack *b, char *flag);
void			rotate_stack(t_stack *stack, char *flag);
void			rotate_rev_stack(t_stack *stack, char *flag);
void			rotate_a_b(t_stack *stack_a, t_stack *stack_b, char *flag);
void			rotate_rev_a_b(t_stack *stack_a, t_stack *stack_b, char *flag);
int				find_index(int *arr, int size, int num);
void			check_flag(char *flag);
void			ft_free(t_stack *b);
int				ft_max(t_stack *stack);
int				ft_min(t_stack *stack);
bool			is_sorted(t_stack *stack);
void			free_args(char **nums);
int				is_exist(int number, t_stack *stack);
void			free_args(char **nums);
void			ft_error(void);
void			check_symbols(char *str, char **res);
int				ft_isalpha(int c);
long long int	ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strlen(const char *s);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
char			*ft_strjoin(char **s1, char const *s2);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *str, int fd);

#endif
