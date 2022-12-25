# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 17:27:09 by zlazrak           #+#    #+#              #
#    Updated: 2022/12/23 17:27:41 by zlazrak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
objs = main.o ft_list.o input.o sort.o libft.o operations.o sort_utils.o sort_utils2.o

all : $(NAME)

$(NAME) : $(objs)
	$(CC) $(CFLAGS) $(objs) -o $(NAME)

.PHONY : all clean fclean re

clean :
	rm -f $(objs)
fclean : clean
	rm -f $(NAME)
re : fclean all
