# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atardy <atardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 11:35:32 by atardy            #+#    #+#              #
#    Updated: 2026/10/14 10:36:19 by atardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

SOURCES = ft_atoi.c \
ft_lstdelone.c \
ft_putendl_fd.c \
ft_strncmp.c \
ft_bzero.c \
ft_lstiter.c \
ft_putnbr_fd.c \
ft_strnstr.c \
ft_calloc.c \
ft_lstlast.c \
ft_putstr_fd.c \
ft_strrchr.c \
ft_isalnum.c \
ft_lstmap.c \
ft_split.c \
ft_strtrim.c \
ft_isalpha.c \
ft_lstnew.c \
ft_strchr.c \
ft_substr.c\
ft_isascii.c \
ft_lstsize.c \
ft_strdup.c \
ft_tolower.c \
ft_isdigit.c \
ft_memchr.c \
ft_striteri.c \
ft_toupper.c \
ft_isprint.c \
ft_memcmp.c \
ft_strjoin.c \
ft_itoa.c \
ft_memcpy.c \
ft_strlcat.c \
ft_lstadd_back.c \
ft_memmove.c \
ft_strlcpy.c \
ft_lstadd_front.c \
ft_memset.c \
ft_strlen.c \
ft_lstclear.c \
ft_putchar_fd.c \
ft_strmapi.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

clean: 
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re