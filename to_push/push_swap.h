/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:00:45 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/20 16:51:29 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

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

/*____input____*/
void		ft_print_error(t_list **stack_a);
long long	ft_atol(char *a, t_list **stack_a);
void		ft_is_integer(char *str, t_list **stack_a);
void		ft_is_duplicate(int data, t_list **stack_a);
void		to_stack_a(int ac, char **av, t_list **stack_a);
/*____l_list____*/
t_list		*ft_lstnew(int data);
void		ft_lstadd_front(t_list **head, t_list *node);
void		ft_lstclear(t_list **head);
t_list		*ft_lstlast(t_list *head);
int			ft_lstsize(t_list *head);
char		**ft_split(char *str);
char		**mem_free(char **str);
void		ft_put_position(t_list *head);
void		ft_bzero(void	*a, int n);
/*____operations____*/
void		ft_putstr(char *s, char c);
void		ft_swap(t_list	**stack, char c);
void		ft_push(t_list	**to_stack, t_list **from_stack, char c);
void		ft_rotate(t_list **stack, char c);
void		ft_reverse_rotate(t_list **stack, char c);
/*____sort____*/
void		ft_sort_three(t_list **stack, char s);
void		ft_sort_less_10(t_list	**stack_a, t_list **stack_b);
t_list		*find_min(t_list *head);
t_list		*find_next_min(t_list *head);
void		ft_sort_index(t_list *stack);
void		ft_sort(t_list **stack_a, t_list **stack_b);
void		ft_from_a_to_b(t_list **a, t_list **b, int n, t_utils u);
void		ft_from_b_to_a(t_list **stack_a, t_list **stack_b);
void		ft_sort_small_range(t_list **stack_a, t_list **stack_b);
int			ft_is_sorted(t_list *stack);
void		ft_b_to_a_util(t_list **stack_b, t_list *max);
void		ft_b_to_a_util2(t_list **stack_b, t_list *max);
t_list		*find_sec_max(t_list *stack);
t_list		*find_max(t_list *stack);
#endif
