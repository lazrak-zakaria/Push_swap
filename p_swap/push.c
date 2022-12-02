#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
typedef struct s_list
{
	int	data;
	int	position;
	int	sort_index;
	struct s_list *next;
	struct s_list *prev;
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
t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list	*head)
{
	while(head->next)
		head = head->next;
	return (head);
}
void	ft_push(t_list **a, t_list **b)
{
	t_list	*node;

	node = *b;
	(*b) = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node->next = *a;
	if (*a)
		(*a)->prev = node;
	node->prev = NULL;
	(*a) = node;
	printf("p\n");
}

void	ft_rotate(t_list **s)
{
	t_list	*node;

	node = ft_lstlast(*s);
	node->next = *s;
	(*s)->prev = node;
	*s = (*s)->next;
	(*s)->prev = NULL;
	node->next->next = NULL;
	printf("rr\n");
}

void	ft_reverse_rotate(t_list **s)
{
	t_list	*node;
	t_list	*last;

	node = *s;
	while(node->next->next)
		node = node->next;
	last = node->next;
	last->next = *s;
	(*s)->prev = last;
	*s = last;
	(*s)->prev = NULL;
	node->next = NULL;
	printf("r\n");
}

void	print(t_list *h)
{
	
	while(h)
	{
		printf("| data = %d | position = %d | sort_index = %d |\n", h->data,h->position,h->sort_index);
		h = h->next;
	}
}

/**********************__________________********************/
t_list	*find_min_node(t_list *head)
{
	t_list * min;
	min = NULL;
	while (head && !min)
	{
		if (!head->sort_index)
			min = head;
		head = head->next;
	}
	while(head)
	{
		if (head->data < min->data && !head->sort_index)
			min = (head);
		head = head->next;
	}
	return min;
}
t_list	*find_min_node1(t_list *head)
{
	t_list*	node;
	int	pos;

	node = head;
	head = head->next;
	while (head)
	{
		if (node->data > head->data)
			node = head;

		head = head->next;
	}
	return node;
}

void	put_sort_index(t_list *head)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		i;

	i = 0;
	tmp = head;
	tmp1 = find_min_node1(tmp);
	tmp1->sort_index = i++;
	//printf(".%d.",tmp1->data);
	while (head)
	{
		tmp1 = find_min_node(tmp);
		tmp1->sort_index = i++;
		//printf(".%d.",tmp1->data);
		head = head->next;
	}
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
/****************_--____------------------****************/

void	sort(t_list **a, t_list **b)
{
	t_list	*head;
	t_list	*tail;


	int s = 1;
	int size2 = ft_lstsize(*a) / 20;
	int size = size2;
	//printf(".%d.",size);
	while (*a)
	{
		while (*a && s <= size)
		 {	
			// printf(".%d.",size);
		// 	printf("h\n");
			head = *a;
			tail = ft_lstlast(*a);
			while ( head && head->sort_index > size)
				head = head->next;
			while (tail && tail->sort_index > size)
				tail = tail->prev;
			if (head && tail && (head->position - (*a)->position <= ft_lstlast(*a)->position - tail->position))
				while (*a && *a != head)
					ft_rotate(a);
			else
				while (tail && *a != tail)
					ft_reverse_rotate(a);
			ft_push(b, a);
			if(*a)
				ft_put_position(*a);
			// print(*a);
			// printf("__\n");
			s++;	
		}
		size += size2;
	}
	
	while (*b)
	{
		head = *b;
		tail = *b;
		while(head)
		{
			if (head->data > tail->data )
				tail = head;
			head = head->next;
		}
		ft_put_position(*b);
		if (tail->position < ft_lstsize(*b)/2)
			while(*b != tail)
				ft_rotate(b);
		else
			while(*b != tail)
				ft_reverse_rotate(b);
		ft_push(a, b);
	}
}
/*    ************________*/
/*    ************________*/
/*    ************________*/
/*    ************________*/
/*    ************________*/
/*    ************________*/
long long ft_atol(char *str)
{
	long long	answer;
	int			sign;
	int			i;

	i = 0;
	answer = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if(str[i++] == '-')
			sign = -1;
	
	while(str[i] >= '0' && str[i] <= '9')
		answer = (answer * 10) + (str[i++] - '0');
	return (answer * sign);
}

void	close_program(t_list *stack)
{
	ft_lstclear(&stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_isdigit_arg(char *str, t_list *stack)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			close_program(stack);
		str++;
	}
}

void	ft_check_limit(long long n, t_list *stack)
{
	if (n > INT_MAX || n < INT_MIN)
		close_program(stack);
}

void	ft_check_duplicate(int n,t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->data == n)
			close_program(stack);
		temp = temp->next;
	}
}

t_list	*organise(int argc, char **argv)
{
	t_list		*stack;
	long long	data;

	stack = NULL;
	while(--argc)
	{
		ft_isdigit_arg(argv[argc], stack);
		data = ft_atol(argv[argc]);
		ft_check_limit(data, stack);
		ft_check_duplicate((int) data, stack);
		ft_lstadd_front(&stack, ft_lstnew((int) data));
	}
	return (stack);
}
/*/************************/
/*/************************/
/*/************************/
/*/************************/
/*/************************/
/*/************************/
/*/************************/

int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	// int	i = 0;
	// while (i++ < 3)
	stack_a = organise(argc, argv);
	t_list *t = stack_a;
	while(t)
	{
		t->sort_index = 0;
		t = t->next;
	}
	
	
	
	
	
	/*
	t_list	*a = NULL;
	t_list	*b = NULL;

	int i = 0;
	while (i<100)
		ft_lstadd_front(&a,ft_lstnew(i++));
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	 ft_push(&b, &a);
	 ft_push(&b, &a);
	 ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	 ft_push(&a, &b);
	 ft_push(&a, &b);
	 ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	 ft_push(&b, &a);
	 ft_push(&b, &a);
	 ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	 ft_push(&a, &b);
	 ft_push(&a, &b);
	 ft_rotate(&a);
	ft_rotate(&a);
	ft_rotate(&a);
	// ft_push(&b, &a);
	// ft_push(&b, &a);
	// ft_push(&b, &a);
	// ft_push(&b, &a);
	//print(a);*/
	ft_put_position(stack_a);
	put_sort_index(stack_a);
	sort(&stack_a, &stack_b); 
	//print(stack_a);
	
}