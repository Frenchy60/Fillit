# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 14:48:54 by agraton           #+#    #+#              #
#    Updated: 2018/07/31 18:14:23 by fverhuls         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = t_pent.h
FLAG = -Wall -Wextra -Werror
OPTION = -o $(NAME) -I $(HEADER)
SRC = mainprogram.c readpentfile.c setpent.c setpent2.c fillitcheck.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OPTION) $(SRC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
