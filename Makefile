# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 16:54:08 by ehasalu           #+#    #+#              #
#    Updated: 2023/01/17 14:11:56 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER =	server
NAME_CLIENT =	client
SRC_SERVER =	server.c
SRC_CLIENT =	client.c
libft_f = libft
libft	= libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(libft) $(NAME_SERVER) $(NAME_CLIENT)

$(libft):
	@make -C $(libft_f)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRC_SERVER) libft/libft.a -o $(NAME_SERVER)
	
$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRC_CLIENT) libft/libft.a -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm $(NAME_SERVER) $(NAME_CLIENT)
	@make clean -C $(libft_f)

fclean: clean
	@make fclean -C $(libft_f)
	
re: fclean all

.PHONY: all clean fclean re
