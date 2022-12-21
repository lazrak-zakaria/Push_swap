/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:44:17 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/09 15:55:02 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **head, t_list *node)
{
	if (!node)
	{
		ft_lstclear(head);
		exit(EXIT_FAILURE);
	}
	if (*head)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
}

void	ft_lstclear(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	while (head)
	{
		if (!(head->next))
			break ;
		head = head->next;
	}
	return (head);
}

int	ft_lstsize(t_list *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		++size;
	}
	return (size);
}
