# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 10:30:01 by iderighe          #+#    #+#              #
#    Updated: 2021/12/13 10:41:57 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
CFS		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -f

LIB		=	-L./Libft -lft

SRC		=	main_pipex.c \

OBJ		=	$(SRC:.c=.o)


all		:	$(NAME)

$(NAME)	:	libft $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

libft	:
			$(MAKE) -C Libft

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

norm	:
			norminette $(SRC)
			norminette pipex.h
			$(MAKE) -C Libft norm

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			$(MAKE) -C Libft fclean

f		:	libft $(OBJ)
			$(CC) $(CFLAGS) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

re		:	fclean all

.PHONY	:	all libft norm clean fclean f fre re
