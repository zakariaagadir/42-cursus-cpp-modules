# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 22:52:35 by zmounji           #+#    #+#              #
#    Updated: 2025/09/05 23:25:24 by zmounji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Weapon.cpp HumanB.cpp HumanA.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
