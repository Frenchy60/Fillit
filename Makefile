# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 14:48:54 by agraton           #+#    #+#              #
#    Updated: 2018/07/24 15:15:29 by agraton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = t_pent.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = mainprogram.c readpentfile.c setpent.c setpent2.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
