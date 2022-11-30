#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				position;
	int				sort_index;
	struct s_list	*next;
	struct s_list	*prev;
} t_list;

void	ft_lstadd_front(t_list **head, t_list *node)
{
		node->next = *head;
		if(*head)
			(*head)->prev = node;
		*head = node;
}

int	ft_lstsize(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return i;
}

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*ft_lst_last(t_list	*head)
{
	while(head->next)
		head = head->next;
	return (head);
}
void	ft_lstclear(t_list **stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
void	ft_swap_first(t_list **stack)
{
	t_list	*node;
	t_list	*node1;

	if (ft_lstsize(*stack) < 2)
		return ;
	node = (*stack);
	node1 = (*stack)->next->next;
	(*stack) = (*stack)->next;
	(*stack)->next = node;
	node->next = node1;
	printf("sa\n");
}

void	ft_swap_first_a_and_b(t_list **stack_a, t_list **stack_b)
{
	ft_swap_first(stack_a);
	ft_swap_first(stack_b);
}

void	ft_push(t_list **stack_one, t_list **stack_two)
{
	t_list	*temp;

	if (!ft_lstsize(*stack_two))
		return ;
	ft_lstadd_front(stack_one, ft_lstnew((*stack_two)->data));
	temp = *stack_two;
	*stack_two = (*stack_two)->next;
	free(temp);
	printf("pa\n");
}

void	ft_stack_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (ft_lstsize(*stack) < 2)
		return ;
	node = *stack;
	last_node = ft_lst_last(*stack);
	last_node->next = node;
	*stack = (*stack)->next;
	node->next = NULL;
	printf("ra\n");
}

void	ft_stack_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	ft_stack_rotate(stack_a);
	ft_stack_rotate(stack_b);
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (ft_lstsize(*stack) < 2)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	printf("rra\n");
}

void	ft_reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

void	ft_put_position(t_list *head)
{
	int	i;

	i = 1;
	while(head)
	{
		head->position = i++;
		head = head->next;
	}
}
void	print(t_list *stack, char *a)
{
		t_list *t = stack;
		printf("stack %s : \n",a);
	while (t)
	{
		printf("data = %d position = %d sort_index = %d\n", t->data, t->position, t->sort_index);
		t = t->next;
	}
	printf("\n");
}/*
int main()
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	int	i = 11;
	while (i--)
		ft_lstadd_front(&stack_a,ft_lstnew(i));
	i = 60;
	while (i > 50)
		ft_lstadd_front(&stack_b,ft_lstnew(i--));
	i = 0;
	print(stack_a,"a");
	print(stack_b,"b");
	// ft_swap_first(&stack_a);
	// print(stack_a,"a");
	printf("------\n");
	//ft_push(&stack_a,&stack_b);
	ft_reverse_rotate(&stack_a);
	print(stack_a,"a");
	print(stack_b,"b");
	return 0;
}*/