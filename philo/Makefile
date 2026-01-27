# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 13:58:23 by olmatske          #+#    #+#              #
#    Updated: 2026/01/27 14:42:49 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SOURCES = main.c validate.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean:
	$(RM) $(NAME) $(OBJECTS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re