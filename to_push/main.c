/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:56:09 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/21 19:41:50 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	to_stack_a(ac, av, &stack_a);
	if (!stack_a)
		exit(EXIT_FAILURE);
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
		ft_sort_small_range(&stack_a, &stack_b);
	else
		ft_sort(&stack_a, &stack_b);
	exit(EXIT_SUCCESS);
}