CC = cc
CFLAGS = -Wall -Wextra -Werror

CBONUS = checker_bonus.c checker_utils_bonus.c get_next_line_bonus.c \
 				get_next_line_utils_bonus.c ft_initialize_bonus.c utils_bonus.c \
				initialize_new_stack_bonus.c operations_bonus.c \
				ft_split_bonus.c ft_strjoin_bonus.c ft_atoi_bonus.c str_funcs_bonus.c \
				ft_isalpha_bonus.c ft_isdigit_bonus.c check_symbols_bonus.c

OBONUS = $(CBONUS:.c=.o)

BONUS = checker

bonus: $(BONUS) 

$(BONUS): $(OBONUS) checker_bonus.h
	$(CC) $(CFLAGS) $(OBONUS) -o $(BONUS)

%.o: %.c checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBONUS)

fclean: clean
	rm -rf $(BONUS)

re: fclean all