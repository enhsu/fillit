# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 21:24:16 by llu               #+#    #+#              #
#    Updated: 2018/12/05 22:30:02 by chsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	./srcs/
INC_PATH	=	./includes/
OBJ_PATH	=	./obj/
LFT_PATH	=	./libft/

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)

INC_NAME	=	fillit.h

SRC_NAME	=	main.c input.c solve.c tool.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
