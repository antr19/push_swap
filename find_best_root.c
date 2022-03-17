/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:40 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 15:08:40 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_score_elem2(int result, t_stack_elem *head, int *ttype)
{
	if (head->b_score + head->a_rscore < result)
	{
		result = head->b_score + head->a_rscore;
		*ttype = 5;
	}
	if (head->b_rscore + head->a_score < result)
	{
		result = head->b_rscore + head->a_score;
		*ttype = 6;
	}
	return (result);
}

static int	find_min_score(t_stack_elem *head, int *ttype)
{
	int	result;
	int	biggest_rscore;

	result = head->b_score;
	*ttype = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		*ttype = 2;
	}
	biggest_rscore = head->a_rscore;
	if (head->b_rscore > biggest_rscore)
		biggest_rscore = head->b_rscore;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (head->b_rscore > head->a_rscore)
			*ttype = 3;
		else
			*ttype = 4;
	}
	result = total_score_elem2(result, head, ttype);
	return (result);
}

t_stack_elem	*find_cheapest_elem(t_stack_elem *head, int *ttype)
{
	t_stack_elem	*ret;
	int				min_score;
	int				cur_score;
	int				best_ttype;
	int				min_order;

	ret = head;
	min_score = find_min_score(head, ttype);
	best_ttype = *ttype;
	min_order = head->order;
	while (head)
	{
		cur_score = find_min_score(head, ttype);
		if (cur_score < min_score || (cur_score == min_score && \
			head->order >= min_order))
		{
			min_score = cur_score;
			best_ttype = *ttype;
			ret = head;
		}
		head = head->next;
	}
	*ttype = best_ttype;
	return (ret);
}
