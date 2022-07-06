/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:34:28 by fmarsha           #+#    #+#             */
/*   Updated: 2022/03/17 16:34:28 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	find_min_med_max(t_stack_elem *head, int *min, int *med, int *max)
{
	int				size;
	int				*arr;
	int				i;
	t_stack_elem	*tmp;

	i = 0;
	size = stack_size(head);
	arr = malloc(sizeof(head->value) * size);
	if (!arr)
		return (1);
	tmp = head;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	array_sort(arr, size);
	*min = arr[0];
	*med = arr[size / 2];
	*max = arr[size - 1];
	define_order(head, arr);
	free(arr);
	return (0);
}

static t_stack_elem	*fill_stack_b(t_stack_elem **head_a)
{
	int				min;
	int				med;
	int				max;
	int				size;
	t_stack_elem	*head_b;

	if (find_min_med_max(*head_a, &min, &med, &max))
		return (NULL);
	size = stack_size(*head_a);
	head_b = NULL;
	while (size > 3)
	{
		if ((*head_a)->value == min || (*head_a)->value == med \
			|| (*head_a)->value == max)
			rotate(head_a, 'a', 1);
		else
		{
			push_to_other_stack(head_a, &head_b, 'b', 1);
			--size;
		}
	}
	if (stack_size(*head_a) == 3 && !sorted(*head_a))
		swap(head_a, 'a', 1);
	return (head_b);
}

void	stack_sort(t_stack_elem **head_a)
{
	t_stack_elem	*head_b;

	if (!sorted(*head_a))
	{
		head_b = fill_stack_b(head_a);
		while (head_b)
			push_to_a(head_a, &head_b);
	}
	final_sort(head_a);
}
