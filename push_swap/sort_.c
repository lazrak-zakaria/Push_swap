#include "take_input.c"


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
		printf(".%d.",tmp1->data);
		head = head->next;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		s;
	int		cs;
	int		size;
	t_list	*head;
	t_list	*tail;

	size = ft_lstsize(*stack_a) / 2;
	int m = size;
	while (*stack_a)
	{
		s = 1;
		while (s <= size)
		{
			head = *stack_a;
			tail = ft_lst_last(*stack_a);
			while (head)
			{
				if(head->sort_index <= size)
					break;
				head = head->next;
			}
			while (tail)
			{
				if(tail->sort_index <= size)
					break;
				tail = tail->prev;
			}
			if (head->position - (*stack_a)->position <  ft_lst_last(*stack_a)->position - tail->position)
				while ((*stack_a)->position != head->position)
					ft_stack_rotate(stack_a);
			else
			{
				while ((*stack_a)->position != tail->position)
					ft_reverse_rotate(stack_a);
			}
			ft_push(stack_b, stack_a);
			s++;
		}
		printf("(()()()");
		ft_put_position(*stack_a);
		size += m;
	}
}

int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	// int	i = 0;
	// while (i++ < 3)
	stack_a = organise(argc,argv);
	t_list *t = stack_a;
	while(t)
	{
		t->sort_index = 0;
		t = t->next;
	}
	 //ft_lstadd_front(&stack_a, ft_lstnew(7));
	 //ft_lstadd_front(&stack_a, ft_lstnew(0));
	ft_put_position(stack_a);
	put_sort_index(stack_a);
	//i = 60;
	//while (i > 50)
	//	ft_lstadd_front(&stack_b,ft_lstnew(i--));
	// i = 0;
	print(stack_a,"a");
	// print(stack_b,"b");
	// ft_swap_first(&stack_a);
	//print(stack_a,"a");
	//printf("------\n%d",find_min_position(stack_a));
	//ft_push(&stack_b, &stack_a);
	// ft_reverse_rotate(&stack_a);
	sort(&stack_a,&stack_b);
	//print(stack_a,"a");
	//print(stack_b,"b");
	return 0;
}