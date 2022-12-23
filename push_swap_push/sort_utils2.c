/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:33:40 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/23 11:35:38 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*node;

	node = stack;
	while (stack)
	{
		if (stack->data > node->data)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

t_list	*find_sec_max(t_list *stack)
{
	t_list	*max;
	t_list	*node;

	max = find_max(stack);
	if (ft_lstsize(stack) == 1)
		return (max);
	if (stack == max)
		node = stack->next;
	else
		node = stack;
	while (stack)
	{
		if (stack->data > node->data && stack != max)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

void	ft_b_to_util(t_list **stack_b, t_list *max)
{
	t_list	*mx2;
	t_utils	utils;

	mx2 = find_sec_max(*stack_b);
	utils.head = *stack_b;
	utils.tail = ft_lstlast(*stack_b);
	while (utils.head)
	{
		if (utils.head == mx2 || utils.head == max)
			break ;
		utils.head = utils.head->next;
	}
	while (utils.tail)
	{
		if (utils.tail == mx2 || utils.tail == max)
			break ;
		utils.tail = utils.tail->prev;
	}
	if ((utils.head->position - (*stack_b)->position)
		<= (ft_lstlast(*stack_b)->position - utils.tail->position))
		while (*stack_b != utils.head)
			ft_rotate(stack_b, 'b');
	else
		while (*stack_b != utils.tail)
			ft_reverse_rotate(stack_b, 'b');
}

void	ft_b_to_util2(t_list **stack_b, t_list *max)
{
	if (max->position <= (ft_lstsize(*stack_b) / 2))
		while (*stack_b != max)
			ft_rotate(stack_b, 'b');
	else
		while (*stack_b != max)
			ft_reverse_rotate(stack_b, 'b');
}

void	ft_from_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	int		f;

	f = 1;
	while (*stack_b)
	{
		ft_put_position(*stack_b);
		max = find_max(*stack_b);
		if (f)
		{
			ft_b_to_util(stack_b, max);
			f = 0;
		}
		else
		{
			ft_b_to_util2(stack_b, max);
			f = 1;
		}
		if (max == *stack_b)
			f = 1;
		ft_push(stack_a, stack_b, 'a');
		if ((*stack_a)->next && ((*stack_a)->data > (*stack_a)->next->data))
			ft_swap(stack_a, 'a');
	}
}
