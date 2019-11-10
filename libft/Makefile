# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgovend <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 11:41:24 by jgovend           #+#    #+#              #
#    Updated: 2018/08/17 10:38:21 by jgovend          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC_PATH := ./srcs

SRC := ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_islower.c ft_isspace.c ft_isprint.c ft_isupper.c ft_itoa.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
	ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
	ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c \
	ft_strnew.c ft_strresize.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_llintlen.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c get_next_line.c ft_root.c ft_power.c

OBJ_PATH := ./objs

OBJ := $(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))

CC := gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "Library objects files compiled."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library archived."

clean:
	@rm -Rf $(OBJ_PATH)
	@echo "Library object files removed."

fclean:	clean 
	@rm -Rf $(NAME)
	@echo "Library removed."

re: fclean all
