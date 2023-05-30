# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:29:40 by gamoreno          #+#    #+#              #
#    Updated: 2023/05/30 22:07:25 by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
NAME		=	phonebook
RM			=	rm -rf

OBJ_PATH	=	objs/
SRC			=	main.cpp \
				Contact.cpp \
				Phonebook.cpp
HEADER		=	Contact.hpp Phonebook.hpp

OBJ			=	$(addprefix $(OBJ_PATH),$(SRC:=.o))
### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m
RED			= \033[0;31m

### RULES ###

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@ $(CC) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREEN) Compilation succesfully.$(NOC)"

$(OBJ_PATH)/%.o: %.cpp $(HEADER)
		@mkdir -p (OBJ_PATH)
		@$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ_PATH) $(OBJ)
		@echo "$(GREEN) Non-executable files removed.$(NOC)"
	
fclean: clean
		@$(RM) $(NAME)
		@echo "$(GREEN) Executable removed$(NOC)"

re: fclean all

.PHONY: all clean fclean re 