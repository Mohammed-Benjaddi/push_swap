CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c push_swap_utils.c ft_range.c ft_sort_five.c ft_sort_three.c \
		ft_sort.c operations.c ft_initialize.c initialize_new_stack.c  utils.c \
		ft_atoi.c ft_isdigit.c ft_split.c ft_strjoin.c ft_strlcpy.c ft_strlen.c  ft_substr.c \
		ft_isalpha.c ft_strdup.c ft_strncmp.c ft_putstr_fd.c


OFILES = $(CFILES:.c=.o)

NAME = push_swap.a
MANDATORY = push_swap

all: $(MANDATORY)

$(MANDATORY): $(NAME) $(OFILES) push_swap.h
	$(CC) $(CFLAGS) $(NAME) -o $(MANDATORY)

$(NAME): $(OFILES) push_swap.h
	ar rcs $(NAME) $(OFILES)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME) $(MANDATORY)

re: fclean all
