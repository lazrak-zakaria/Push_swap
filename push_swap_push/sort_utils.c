/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:35:56 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/23 11:36:24 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *head)
{
	t_list	*node;

	node = head;
	while (head)
	{
		if (head->data < node->data)
			node = head;
		head = head->next;
	}
	return (node);
}

t_list	*find_next_min(t_list *head)
{
	t_list	*min;

	while (head)
	{
		if (!(head->sort_index))
		{
			min = head;
			break ;
		}
		head = head->next;
	}
	while (head)
	{
		if ((head->data < min->data) && !(head->sort_index))
			min = head;
		head = head->next;
	}
	return (min);
}

void	ft_sort_index(t_list *stack)
{
	int		size;
	int		i;
	t_list	*min;

	i = 1;
	min = find_min(stack);
	min->sort_index = i++;
	size = ft_lstsize(stack);
	while (i <= size)
	{
		min = find_next_min(stack);
		min->sort_index = i++;
	}
}

int	ft_is_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack->next && stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_put_position(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i++;
		stack = stack->next;
	}
}
