/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:06:03 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/05 13:06:03 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_elem *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack_elem	*create_elem(int value)
{
	t_stack_elem	*new;

	new = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!new)
		return (NULL);
	new->value = value;
	new->a_rscore = -1;
	new->b_rscore = -1;
	new->a_score = -1;
	new->b_score = -1;
	new->order = -1;
	new->next = NULL;
	return (new);
}

void	push_back(t_stack_elem **head, t_stack_elem *new)
{
	t_stack_elem	*begin;

	begin = *head;
	if (!begin)
	{
		*head = new;
		return ;
	}
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}

t_stack_elem	*record_stack(int argc, char **argv)
{
	int				i;
	t_stack_elem	*head;

	i = 0;
	head = NULL;
	while (++i < argc)
		push_back(&head, create_elem(ft_atoi(argv[i])));
	return (head);
}

void	free_stack(t_stack_elem **head)
{
	t_stack_elem	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
	*head = NULL;
}
