# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 11:41:24 by jgovend           #+#    #+#              #
#    Updated: 2018/08/15 22:50:57 by jordan_maco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := jgovend.filler

SRC_PATH := ./srcs

SRC := filler.c placement.c supp.c

OBJ_PATH := ./objs

OBJ := $(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))

LIB_PATH := ./libft

LIB := libft.a

CC := gcc

FLAGS := -Wall -Werror -Wextra  -Iincludes

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ_PATH) $(OBJ)
	@make re -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ) $(LIB_PATH)/$(LIB) -o ./players/$(NAME)

clean:
	rm -Rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIB_PATH)
	rm -Rf ./players/$(NAME)
	rm -Rf *.trace

re: fclean all
