/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:45:22 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 16:45:22 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_elem **head, char stack_name, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = *head;
		while (before_last->next->next)
			before_last = before_last->next;
		before_last->next->next = *head;
		*head = before_last->next;
		before_last->next = NULL;
		if (output)
		{
			write(1, "rr", 2);
			write(1, &stack_name, 1);
			write(1, "\n", 1);
		}
	}
}

void	double_rev_rotate(t_stack_elem **head_a, t_stack_elem **head_b, \
		int output)
{
	rev_rotate(head_a, 'a', 0);
	rev_rotate(head_b, 'b', 0);
	if (output)
		write(1, "rrr\n", 4);
}
