/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:59:42 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 15:59:42 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rotations2(t_stack_elem **head_a, t_stack_elem **head_b, \
			t_stack_elem *elem, int ttype)
{
	if (ttype == 4)
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore--)
			double_rev_rotate(head_a, head_b, 1);
		while (elem->a_rscore-- > 0)
			rev_rotate(head_a, 'a', 1);
	}
	if (ttype == 5)
	{
		while (elem->b_score-- > 0)
			rotate(head_b, 'b', 1);
		while (elem->a_rscore-- > 0)
			rev_rotate(head_a, 'a', 1);
	}
	if (ttype == 6)
	{
		while (elem->b_rscore-- > 0)
			rev_rotate(head_b, 'b', 1);
		while (elem->a_score-- > 0)
			rotate(head_a, 'a', 1);
	}
}

void	execute_rotations(t_stack_elem **head_a, t_stack_elem **head_b, \
			t_stack_elem *elem, int ttype)
{
	if (ttype == 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			double_rotate(head_a, head_b, 1);
		while (elem->b_score-- > 0)
			rotate(head_b, 'b', 1);
	}
	if (ttype == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			double_rotate(head_a, head_b, 1);
		while (elem->a_score-- > 0)
			rotate(head_a, 'a', 1);
	}
	if (ttype == 3)
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore--)
			double_rev_rotate(head_a, head_b, 1);
		while (elem->b_rscore-- > 0)
			rev_rotate(head_b, 'b', 1);
	}
	if (ttype > 3)
		execute_rotations2(head_a, head_b, elem, ttype);
	push_to_other_stack(head_b, head_a, 'a', 1);
}
