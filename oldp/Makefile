NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
objs = ft_list.o input.o main.o sort.o libft.o operations.o sort_utils.o

all : $(NAME)

$(NAME) : $(objs)
	$(CC) $(CFLAGS) $(objs) -o $(NAME)

.PHONY : all clean fclean re

clean :
	rm -f $(objs)
fclean : clean
	rm -f $(NAME)
re : fclean all