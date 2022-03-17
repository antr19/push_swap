/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:31 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 15:08:31 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	define_order_case_sorted(t_stack_elem *head)
{
	int				size;
	int				*arr;
	int				i;
	t_stack_elem	*tmp;

	i = 0;
	size = stack_size(head);
	arr = malloc(sizeof(head->value) * size);
	if (!arr)
		return ;
	tmp = head;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	array_sort(arr, size);
	define_order(head, arr);
	free(arr);
}

void	final_sort(t_stack_elem **head)
{
	t_stack_elem	*tmp;
	int				count;
	int				size;

	size = stack_size(*head);
	count = 0;
	tmp = *head;
	if (tmp->order == -1)
		define_order_case_sorted(*head);
	while (tmp && tmp->order)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= size - count)
	{
		while (count-- > 0)
			rotate(head, 'a', 1);
	}
	else
	{
		while (count++ < size)
			rev_rotate(head, 'a', 1);
	}
}
