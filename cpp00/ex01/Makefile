# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:29:40 by gamoreno          #+#    #+#              #
#    Updated: 2023/06/06 23:06:38by gamoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME		=	phonebook
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I $(HEADER)

###  PATHS ###
SRC_PATH	=	sources/
HEADER		=	includes/
OBJ_PATH	=	objs/

### FILES ###
SOURCES		=	main.cpp \
				Contact.cpp \
				PhoneBook.cpp

### FILE MANAGEMENT ###
SRCS		=	$(addprefix $(SRC_PATH),$(SOURCES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.o))
DEPS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.d))	

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all: tmp $(NAME)


tmp:
		@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Compilation succesfully.$(NOC)"

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

-include $(DEPS)

.PHONY: all clean fclean re 