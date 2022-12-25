/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:33:31 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/23 11:36:46 by zlazrak          ###   ########.fr       */
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
	node->sort_index = 0;
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
		(*head)->prev = node;
	node->next = *head;
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
		size++;
		head = head->next;
	}
	return (size);
}
