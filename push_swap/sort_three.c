#include "push_swap.c"
#include "take_input.c"

void	sort_three(t_list **stack_a)
{
	int	a[3];

	a[0] = (*stack_a)->data;
	a[1] = (*stack_a)->next->data;
	a[2] = (*stack_a)->next->next->data;
	if (a[0] < a[2] && a[2] < a[1])
	{
		ft_reverse_rotate(stack_a);
		ft_swap_first(stack_a);
	}
	else if (a[1] < a[0] && a[0] < a[2])
		ft_swap_first(stack_a);
	else if (a[0] < a[1] && a[2] < a[0])
		ft_reverse_rotate(stack_a);
	else if (a[1] < a[2] && a[2] < a[0])
		ft_stack_rotate(stack_a);
	else if (a[2] < a[1] && a[1] < a[0])
	{
		ft_stack_rotate(stack_a);
		ft_swap_first(stack_a);
	}
}
/*
int	find_min_position(t_list *head)
{
	int	data;
	int	pos;

	data = head->data;
	pos = head->position;
	head = head->next;
	while (head)
	{
		if (data > head->data)
		{
			pos = head->position;
			//printf(".%d.",pos);
			data = head->data;
		}
		head = head->next;
	}
//	printf(".%d.",pos);
	return pos;
}

void	sort(t_list **a, t_list **b)
{
	int	pos;
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		pos = find_min_position(*a);
		//printf(".%d .  ",pos);
		if (pos == 1)
			ft_push(b,a);
	
	
		else if (pos == 2)
		{
			ft_swap_first(a);
			ft_push(b,a);
	
		}
		else if (pos > size / 2 )
		{
			while (find_min_position(*a) != 1)
			{
				ft_reverse_rotate(a);
				ft_put_position(*a);
			}
			ft_push(b,a);
	
		}
		else if (pos <= size / 2 )
		{
			while (find_min_position(*a) != 1)
			{
				ft_stack_rotate(a);
				ft_put_position(*a);
			}
			ft_push(b,a);
		}
		size = ft_lstsize(*a);
		ft_put_position(*a);
	}
	sort_3(a);
	while (*b)
		ft_push(a, b);
	ft_put_position(*a);
}
*/
int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	// int	i = 0;
	// while (i++ < 3)
	stack_a = organise(argc,argv);

	// ft_lstadd_front(&stack_a, ft_lstnew(7));
	// ft_lstadd_front(&stack_a, ft_lstnew(0));
	ft_put_position(stack_a);
	//i = 60;
	//while (i > 50)
	//	ft_lstadd_front(&stack_b,ft_lstnew(i--));
	// i = 0;
	print(stack_a,"a");
	// print(stack_b,"b");
	// ft_swap_first(&stack_a);
	// print(stack_a,"a");
	//printf("------\n%d",find_min_position(stack_a));
	//ft_push(&stack_b, &stack_a);
	// ft_reverse_rotate(&stack_a);
	sort(&stack_a,&stack_b);
	//print(stack_a,"a");
	//print(stack_b,"b");
	return 0;
}
// /
// 1 3 2   2 1 3   1 2 3
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1