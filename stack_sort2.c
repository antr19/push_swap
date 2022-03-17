/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:59:09 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 15:59:09 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_elem	*last_elem(t_stack_elem *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

static void	rotation_score_b(t_stack_elem *head)
{
	int	size;
	int	i;

	size = stack_size(head);
	i = 0;
	while (head)
	{
		head->b_score = i;
		head->b_rscore = size - i;
		++i;
		head = head->next;
	}
}

static void	rotation_score_a(t_stack_elem *head_a, t_stack_elem *head_b)
{
	t_stack_elem	*curr_a;
	t_stack_elem	*prev_a;
	int				i;
	int				size;

	curr_a = head_a;
	size = stack_size(head_a);
	while (head_b)
	{
		curr_a = head_a;
		prev_a = last_elem(head_a);
		i = 0;
		while (curr_a)
		{
			if (head_b->value < curr_a->value && head_b->value > prev_a->value)
			{
				head_b->a_score = i;
				head_b->a_rscore = size - i;
			}
			++i;
			prev_a = curr_a;
			curr_a = curr_a->next;
		}
		head_b = head_b->next;
	}
}

void	push_to_a(t_stack_elem **head_a, t_stack_elem **head_b)
{
	int				ttype;
	t_stack_elem	*cheapest_elem;

	rotation_score_b(*head_b);
	rotation_score_a(*head_a, *head_b);
	cheapest_elem = find_cheapest_elem(*head_b, &ttype);
	execute_rotations(head_a, head_b, cheapest_elem, ttype);
}
