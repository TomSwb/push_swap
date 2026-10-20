# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 11:33:03 by tschwab           #+#    #+#              #
#    Updated: 2026/10/20 21:12:11 by tschwab          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PARSING = parsing/parsing.c \
		parsing/parsing_utils.c \
		parsing/parsing_utils_2.c \
		parsing/disorder_ranks.c

MOVES = moves/p_moves.c \
		moves/r_moves.c \
		moves/rr_moves.c \
		moves/s_moves.c

ALGOS =	algos/on2.c \
		algos/onrootn.c \
		algos/onlogn.c

SRCS = main.c ${PARSING} ${MOVES} ${ALGOS} \
		tests.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re