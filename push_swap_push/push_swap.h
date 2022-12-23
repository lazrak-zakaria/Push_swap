/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:33:55 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/23 11:38:34 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				position;
	int				sort_index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_utils
{
	int		start;
	int		end;
	int		size;
	t_list	*head;
	t_list	*tail;
}	t_utils;

t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **head, t_list *node);
void	ft_lstclear(t_list **head);
t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *head);

char	**ft_split(char *str);
void	ft_bzero(void *a, int n);
char	**mem_free(char **str);

void	to_stack_a(int ac, char **av, t_list **stack_a);

void	ft_swap(t_list **stack, char c);
void	ft_push(t_list **to_stack, t_list **from_stack, char c);
void	ft_rotate(t_list **stack, char c);
void	ft_reverse_rotate(t_list **stack, char c);

t_list	*find_min(t_list *head);
void	ft_sort_index(t_list *stack);
int		ft_is_sorted(t_list *stack);
void	ft_put_position(t_list *stack);

void	ft_from_b_to_a(t_list **stack_a, t_list **stack_b);

void	ft_sort_three(t_list **stack, char s);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort_small(t_list **stack_a, t_list **stack_b);
#endif
