#include "take_input.c"

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
	//ft_put_position(stack_a);
	put_sort_index(stack_a);
	//i = 60;
	//while (i > 50)
	//	ft_lstadd_front(&stack_b,ft_lstnew(i--));
	// i = 0;
	//print(stack_a,"a");
	// print(stack_b,"b");
	// ft_swap_first(&stack_a);
	//print(stack_a,"a");
	//printf("------\n%d",find_min_position(stack_a));
	//ft_push(&stack_b, &stack_a);
	// ft_reverse_rotate(&stack_a);
	//sort(&stack_a,&stack_b);
	//print(stack_a,"a");
	//print(stack_b,"b");
	return 0;
}