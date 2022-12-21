/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:49:08 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/06 16:51:44 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	**stack, char c)
{
	t_list	*node;

	if (ft_lstsize(*stack) < 2)
		return ;
	node = (*stack)->next;
	(*stack)->next = node->next;
	(*stack)->prev = node;
	node->prev = NULL;
	node->next = (*stack);
	if ((*stack)->next)
		(*stack)->next->prev = (*stack);
	*stack = node;
	ft_putstr("s", c);
}

void	ft_push(t_list	**to_stack, t_list **from_stack, char c)
{
	t_list	*node;

	node = *from_stack;
	(*from_stack) = node->next;
	if (*from_stack)
		(*from_stack)->prev = NULL;
	if (*to_stack)
		(*to_stack)->prev = node;
	node->next = (*to_stack);
	*to_stack = node;
	ft_putstr("p", c);
}

void	ft_rotate(t_list **stack, char c)
{
	t_list	*last_node;

	if (ft_lstsize(*stack) < 2)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	ft_putstr("r", c);
}

void	ft_reverse_rotate(t_list **stack, char c)
{
	t_list	*node;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	node = *stack;
	while (node->next->next)
		node = node->next;
	last = node->next;
	last->next = *stack;
	(*stack)->prev = last;
	(*stack) = last;
	(*stack)->prev = NULL;
	node->next = NULL;
	ft_putstr("rr", c);
}

void	ft_putstr(char *s, char c)
{
	while (*s)
		write (1, s++, 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
