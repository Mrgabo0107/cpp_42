# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 22:43:27 by gamoreno          #+#    #+#              #
#    Updated: 2023/05/29 22:43:31 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		=		c++
FLAGS	=		-Wall -Wextra -Werror -std=c++98
NAME	= 		megaphone

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m
RED			= \033[0;31m

### RULES ###

all: $(NAME)

$(NAME):
		@ $(CC) $(FLAGS) megaphone.cpp -o $(NAME)
		@echo "$(GREEN) Compilation succesfully$(NOC)"

clean:
		@echo "$(RED) There's no non-executable files to remove$(NOC)"

fclean:
		@rm -rf $(NAME)
		@echo "$(GREEN) Executable removed$(NOC)"

re:	fclean all

.PHONY:	all clean fclean re 