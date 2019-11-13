# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 11:50:27 by selgrabl          #+#    #+#              #
#    Updated: 2019/11/13 18:42:45 by selgrabl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	./ft_printf.c	\
		./ft_conv.c		\
		./flag.c		\
		./process.c		\
		./tools.c		\
		./tools2.c		\


OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror -I./includes

all: $(NAME)

$(NAME)	:	$(OBJ)
	ar rc	$(NAME) $(OBJ)
	ranlib	$(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean