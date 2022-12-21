/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:46:17 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/20 13:59:32 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(t_list **stack_a)
{
	ft_lstclear(stack_a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long long	ft_atol(char *a, t_list **stack_a)
{
	long long	answer;
	int			sign;
	int			i;

	answer = 0;
	sign = 1;
	i = 0;
	if (a[i] == '+' || a[i] == '-')
		if (a[i++] == '-')
			sign = -1;
	if (!(a[i] >= '0' && a[i] <= '9'))
		ft_print_error(stack_a);
	while (a[i] >= '0' && a[i] <= '9')
		answer = (answer * 10) + (a[i++] - '0');
	answer = answer * sign;
	if (answer > INT_MAX || answer < INT_MIN)
		ft_print_error(stack_a);
	return (answer);
}

void	ft_is_integer(char *str, t_list **stack_a)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_print_error(stack_a);
		i++;
	}
}

void	ft_is_duplicate(int data, t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	while (head)
	{
		if (head->data == data)
			ft_print_error(stack_a);
		head = head->next;
	}
}

void	to_stack_a(int ac, char **av, t_list **stack_a)
{
	int		data;
	int		f;

	f = 0;
	if (ac == 2)
	{
		av = ft_split(av[1]);
		f = 1;
		if (!av)
			exit(EXIT_FAILURE);
		ac = 0;
		while (av[ac])
			ac++;
	}
	while (--ac)
	{
		ft_is_integer(av[ac], stack_a);
		data = ft_atol(av[ac], stack_a);
		ft_is_duplicate(data, stack_a);
		ft_lstadd_front(stack_a, ft_lstnew(data));
	}
	if (f)
		mem_free(av);
}
