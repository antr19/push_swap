/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:59:02 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 15:59:02 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	sorted(t_stack_elem *head)
{
	t_stack_elem	*begin;
	int				flag;

	begin = head;
	flag = 0;
	while (head && head->next)
	{
		if (head->next->value < head->value && flag)
			return (0);
		if (head->next->value < head->value)
			flag = 1;
		head = head->next;
	}
	if (head->value > begin->value && flag)
		return (0);
	return (1);
}

void	define_order(t_stack_elem *head, int *arr)
{
	int	i;

	while (head)
	{
		i = 0;
		while (arr[i] != head->value)
			i++;
		head->order = i;
		head = head->next;
	}
}

static int	find_min_med_max(t_stack_elem *head, int *min, t_stack_elem	**max_cur, int *max)
{
	int				size;
	int				*arr;
	int				i;
	int				max_len;
	int				len;
	t_stack_elem	*cur;
	t_stack_elem	*tmp;

	i = 0;
	len = 1;
	max_len = 1;
	size = stack_size(head);
	arr = malloc(sizeof(head->value) * size);
	if (!arr)
		return (1);
	tmp = head;
	cur = head;
	*max_cur = cur;
	while (tmp)
	{
		if (tmp->next && (tmp->next->value > tmp->value))
			len++;
		else
		{
			if (len > max_len)
			{
				max_len = len;
				*max_cur = cur;
			}
			cur = tmp->next;
			len = 1;
		}
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	array_sort(arr, size);
	*min = arr[0];
	// *med = arr[size / 2];	
	*max = arr[size - 1];
	define_order(head, arr);
	free(arr);
	return (0);
}

static t_stack_elem	*fill_stack_b(t_stack_elem **head_a)
{
	int				min;
	int				max;
	int				size;
	t_stack_elem	*head_b;
	t_stack_elem	*sorted_part;

	printf("fill_stack\n");
	if (find_min_med_max(*head_a, &min, &sorted_part, &max))
		return (NULL);
	printf("find\n");
	size = stack_size(*head_a);
	head_b = NULL;
	while (size)
	{
		if ((*head_a)->value == min || (*head_a == sorted_part) || (*head_a)->value == max)
		{
			rotate(head_a, 'a', 1);
			if (sorted_part->next && (sorted_part->next->value > sorted_part->value))
				sorted_part = sorted_part->next;
		}
		else
			push_to_other_stack(head_a, &head_b, 'b', 1);
		--size;
	}
	if (!sorted(*head_a))//(stack_size(*head_a) == 2 && !sorted(*head_a))
		swap(head_a, 'a', 1);
	return (head_b);
}

void	stack_sort(t_stack_elem **head_a)
{
	t_stack_elem	*head_b;

	printf("stack_sort\n");
	if (!sorted(*head_a))
	{
		head_b = fill_stack_b(head_a);
		while (head_b)
			push_to_a(head_a, &head_b);
	}
	final_sort(head_a);
}
