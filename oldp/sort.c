/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:53:46 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/19 09:18:01 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_sort_three(t_list **stack, char s)
{
	int	a[3];

	a[0] = (*stack)->data;
	a[1] = (*stack)->next->data;
	a[2] = (*stack)->next->next->data;
	if (a[0] < a[2] && a[2] < a[1])
	{
		ft_reverse_rotate(stack, s);
		ft_swap(stack, s);
	}
	else if (a[1] < a[0] && a[0] < a[2])
		ft_swap(stack, s);
	else if (a[2] < a[0] && a[0] < a[1])
		ft_reverse_rotate(stack, s);
	else if (a[1] < a[2] && a[2] < a[0])
		ft_rotate(stack, s);
	else if (a[2] < a[1] && a[1] < a[0])
	{
		ft_rotate(stack, s);
		ft_swap(stack, s);
	}
}

void	ft_from_a_to_b(t_list **stack_a, t_list **stack_b, int n, t_utils utils)
{
	utils.size = ft_lstsize(*stack_a) / n;
	utils.end = utils.size;
	utils.start = 1;
	while (*stack_a)
	{
		while (*stack_a && utils.start++ <= utils.end)
		{
			ft_put_position(*stack_a);
			utils.head = *stack_a;
			utils.tail = ft_lstlast(*stack_a);
			while (utils.head && utils.head->sort_index > utils.end)
				utils.head = utils.head->next;
			while (utils.tail && utils.tail->sort_index > utils.end)
				utils.tail = utils.tail->prev;
			if (utils.head->position - (*stack_a)->position
				<= (ft_lstlast(*stack_a))->position - utils.tail->position)
				while (*stack_a != utils.head)
					ft_rotate(stack_a, 'a');
			else
				while (*stack_a != utils.tail)
					ft_reverse_rotate(stack_a, 'a');
			ft_push(stack_b, stack_a, 'b');
		}
		utils.end += utils.size;
	}	
}

void	ft_from_b_to_a(t_list **stack_a, t_list **stack_b, t_utils utils)
{
	t_list	*node;

	while (*stack_b)
	{
		ft_put_position(*stack_b);
		utils.head = *stack_b;
		node = *stack_b;
		while (utils.head)
		{
			if (node->data < utils.head->data)
				node = utils.head;
			utils.head = utils.head->next;
		}
		if (node->position <= ft_lstsize(*stack_b) / 2)
			while (*stack_b != node)
				ft_rotate(stack_b, 'b');
		else
			while (*stack_b != node)
				ft_reverse_rotate(stack_b, 'b');
		ft_push(stack_a, stack_b, 'a');
	}
}

t_list	*find_max(t_list *stack)
{
	t_list *node;

	node = stack;
	while(stack)
	{
		if (stack->data > node->data)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

t_list	*find_sec_max(t_list *stack)
{
	t_list *max;
	t_list *node;

	max = find_max(stack);
	if (ft_lstsize(stack) == 1)
		return max;
	while (stack)
	{
		if (stack != max)
		{
			node = stack;
			break;
		}
		stack = stack->next;
	}
	while (stack)
	{
		if (stack->data > node->data && stack != max)
			node = stack;
		stack = stack->next;
	}
	return node;
}

void	ft_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	t_list	*node;
	int		f;

	t_utils utils;

	f = 1;
	while (*stack_b)
	{
		ft_put_position(*stack_b);
		max = find_max(*stack_b);
		node = find_sec_max(*stack_b);
		if (f)
		{
			utils.head = *stack_b;
			utils.tail = ft_lstlast(*stack_b);
			while (utils.head)
			{	if (utils.head == max || utils.head == node) break; utils.head = utils.head->next;}
			while (utils.tail )
			{ if (utils.tail == max || utils.tail == node) break; utils.tail = utils.tail->prev; }
			if (utils.head->position - (*stack_b)->position
				<= (ft_lstlast(*stack_b))->position - utils.tail->position)
				while (*stack_b != utils.head)
					ft_rotate(stack_b, 'b');
			else
				while (*stack_b != utils.tail)
					ft_reverse_rotate(stack_b, 'b');
			f = 0;
		}
		else 
		{
			if (max->position <= ft_lstsize(*stack_b) / 2)
				while (*stack_b != max)
					ft_rotate(stack_b, 'b');
			else
				while (*stack_b != max)
					ft_reverse_rotate(stack_b, 'b');
			f = 1;
		}
		ft_push(stack_a, stack_b, 'a');
		if ((*stack_a)->next && ((*stack_a)->data > (*stack_a)->next->data))
			ft_swap(stack_a, 'a');
	}
}
void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_utils	utils;
	int		n;

	n = ft_lstsize(*stack_a);
	if (n < 60)
		n = 5;
	else if (n < 120)
		n = 9;
	else if (n < 300)
		n = 13;
	else
		n = 20;
	ft_bzero(&utils, sizeof(t_utils));
	ft_from_a_to_b(stack_a, stack_b, n, utils);
	ft_b_to_a(stack_a, stack_b);

}

void	ft_sort_small_range(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_utils	utils;

	while (ft_lstsize(*stack_a) > 3)
	{
		ft_put_position(*stack_a);
		node = find_min(*stack_a);
		if (node->position <= ft_lstsize(*stack_a) / 2)
			while (*stack_a != node)
				ft_rotate(stack_a, 'a');
		else
			while (*stack_a != node)
				ft_reverse_rotate(stack_a, 'a');
		ft_push(stack_b, stack_a, 'b');
	}
	ft_sort_three(stack_a, 'a');
	ft_bzero(&utils, sizeof(t_utils));
	ft_from_b_to_a(stack_a, stack_b, utils);
}