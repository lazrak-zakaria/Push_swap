#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "push_swap.c"
long long ft_atol(char *str)
{
	long long	answer;
	int			sign;
	int			i;

	i = 0;
	answer = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if(str[i++] == '-')
			sign = -1;
	
	while(str[i] >= '0' && str[i] <= '9')
		answer = (answer * 10) + (str[i++] - '0');
	return (answer * sign);
}

void	close_program(t_list *stack)
{
	ft_lstclear(&stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_isdigit_arg(char *str, t_list *stack)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			close_program(stack);
		str++;
	}
}

void	ft_check_limit(long long n, t_list *stack)
{
	if (n > INT_MAX || n < INT_MIN)
		close_program(stack);
}

void	ft_check_duplicate(int n,t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->data == n)
			close_program(stack);
		temp = temp->next;
	}
}

t_list	*organise(int argc, char **argv)
{
	t_list		*stack;
	long long	data;

	stack = NULL;
	while(--argc)
	{
		ft_isdigit_arg(argv[argc], stack);
		data = ft_atol(argv[argc]);
		ft_check_limit(data, stack);
		ft_check_duplicate((int) data, stack);
		ft_lstadd_front(&stack, ft_lstnew((int) data));
	}
	return (stack);
}