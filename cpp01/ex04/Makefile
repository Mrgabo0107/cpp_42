# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 22:43:27 by gamoreno          #+#    #+#              #
#    Updated: 2023/06/12 03:01:37 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= replaceString


### PATHS ###
OBJ_PATH	=	objs/
SRC_PATH	=	sources/

### FILES ###
SOURCES		=	main.cpp

### FILE MANAGEMENT ###
SRCS		=	$(addprefix $(SRC_PATH),$(SOURCES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.o))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all: tmp $(NAME)

tmp:
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
		@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Compilation succesfully$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		@$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ_PATH)
		@echo "$(GREEN) Non-executable files removed.$(NOC)"
	
fclean: clean
		@$(RM) $(NAME)
		@echo "$(GREEN) Executable removed$(NOC)"

re: fclean all

RM			=	rm -rf

.PHONY:	all clean fclean re 