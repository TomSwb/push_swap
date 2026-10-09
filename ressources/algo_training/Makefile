# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/01 23:17:43 by tomswb            #+#    #+#              #
#    Updated: 2026/10/09 08:46:27 by tomswb           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sort

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

ON2 = on2_test.c \
	./algorithm_on2/bubble_sort.c \
	./algorithm_on2/bubble_sort_tester.c \
	./algorithm_on2/cocktail_shaker_sort.c \
	./algorithm_on2/cocktail_shaker_sort_tester.c \
	./algorithm_on2/insertion_sort.c \
	./algorithm_on2/insertion_sort_tester.c \
	./algorithm_on2/selection_sort.c \
	./algorithm_on2/selection_sort_tester.c \
	./algorithm_on2/shell_sort.c \
	./algorithm_on2/shell_sort_tester.c

ONLOGN = onlogn_test.c \
	./algorithm_onlogn/merge_sort.c \
	./algorithm_onlogn/merge_sort_tester.c \
	./algorithm_onlogn/quick_sort.c \
	./algorithm_onlogn/quick_sort_tester.c

ONK = onk_test.c \
	./algorithm_onk/radix_sort.c \
	./algorithm_onk/radix_sort_tester.c

SRCS = main.c ${ON2} ${ONLOGN} ${ONK}

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c algo_training.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re