/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:33:11 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/24 11:05:41 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(int ac, char **av, t_list **stack)
{
	if (ac == 2 && !(*stack) && av[1][0])
		ft_print_error(stack);
	if (!(*stack))
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	to_stack_a(ac, av, &stack_a);
	check(ac, av, &stack_a);
	ft_sort_index(stack_a);
	if (ft_lstsize(stack_a) < 2 || ft_is_sorted(stack_a))
		exit(EXIT_SUCCESS);
	else if (ft_lstsize(stack_a) < 3)
	{
		if (stack_a->data > stack_a->next->data)
			ft_rotate(&stack_a, 'a');
	}
	else if (ft_lstsize(stack_a) < 4)
		ft_sort_three(&stack_a, 'a');
	else if (ft_lstsize(stack_a) <= 20)
		ft_sort_small(&stack_a, &stack_b);
	else
		ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(EXIT_SUCCESS);
}
