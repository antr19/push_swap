#include "push_swap.h"
#include <stdio.h>
void	print_stack(t_stack_elem *head)
{
	int i = 0;
	printf("=========stack===========\n");
	while (head)
	{
		printf("%d) %d\n", i, head->value);
		i++;
		head = head->next;
	}
	printf("======end of stack=======\n");
}

void	print_stacks(t_stack_elem *head_a, t_stack_elem *head_b)
{
	while (head_a && head_b)
	{
		printf("%5d%5d\n", head_a->value, head_b->value);
		head_a = head_a->next;
		head_b = head_b->next;
	}
	while (!head_a && head_b)
	{
		printf("     %5d\n", head_b->value);
		head_b = head_b->next;
	}
	while (head_a && !head_b)
	{
		printf("%5d     \n", head_a->value);
		head_a = head_a->next;
	}
	printf("----a----b\n");
	printf("----------\n");
}

void	print_array(int *arr, int size)
{
	int i = -1;
	printf("=========array===========\n");
	while (++i < size)
		printf("%d) %d\n", i, arr[i]);
	printf("======end of array=======\n");
}

void	print_elem_info(t_stack_elem *elem)
{
	printf("value: %-6da: %-3d b: %-3drev_a: %-3drev_b: %-3dorder: %-3d\n", elem->value, elem->a_score, elem->b_score, elem->a_rscore, elem->b_rscore, elem->order);
}