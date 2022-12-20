/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:53:11 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/06 16:51:52 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *head)
{
	t_list	*node;

	node = head;
	while (head)
	{
		if (node->data > head->data)
			node = head;
		head = head->next;
	}
	return (node);
}

t_list	*find_next_min(t_list *head)
{
	t_list	*min_node;

	while (head)
	{
		if (!head->sort_index)
		{
			min_node = head;
			break ;
		}
		head = head->next;
	}
	while (head)
	{
		if (head->data < min_node->data && !head->sort_index)
			min_node = head;
		head = head->next;
	}
	return (min_node);
}

void	ft_sort_index(t_list *stack)
{
	int		i;
	int		size;
	t_list	*min_node;

	i = 1;
	min_node = stack;
	while (min_node)
	{
		min_node->sort_index = 0;
		min_node = min_node->next;
	}
	min_node = find_min(stack);
	min_node->sort_index = i++;
	size = ft_lstsize(stack);
	while (i <= size)
	{
		min_node = find_next_min(stack);
		min_node->sort_index = i++;
	}
}

int	ft_is_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack->next && (stack->next->data < stack->data))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_put_position(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head->position = i++;
		head = head->next;
	}
}
