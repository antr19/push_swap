/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:31:34 by fmarsha           #+#    #+#             */
/*   Updated: 2022/03/17 17:40:42 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_finally_sorted(t_stack_elem *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	do_action(t_stack_elem **head_a, t_stack_elem **head_b,
			char *action)
{
	if (ft_strncmp(action, "sa") == 0)
		swap(head_a, 'a', 0);
	else if (ft_strncmp(action, "sb") == 0)
		swap(head_b, 'b', 0);
	else if (ft_strncmp(action, "ss") == 0)
		double_swap(head_a, head_b, 0);
	else if (ft_strncmp(action, "pa") == 0)
		push_to_other_stack(head_b, head_a, 'a', 0);
	else if (ft_strncmp(action, "pb") == 0)
		push_to_other_stack(head_a, head_b, 'b', 0);
	else if (ft_strncmp(action, "ra") == 0)
		rotate(head_a, 'a', 0);
	else if (ft_strncmp(action, "rb") == 0)
		rotate(head_b, 'b', 0);
	else if (ft_strncmp(action, "rra") == 0)
		rev_rotate(head_a, 'a', 0);
	else if (ft_strncmp(action, "rrb") == 0)
		rev_rotate(head_b, 'b', 0);
	else if (ft_strncmp(action, "rrr") == 0)
		double_rev_rotate(head_a, head_b, 0);
	else if (ft_strncmp(action, "rr") == 0)
		double_rotate(head_a, head_b, 0);
	else
		return (1);
	return (0);
}

static int	read_stdin(char (*buf)[5])
{
	int		size;
	char	symbol[2];

	*buf[0] = '\0';
	size = read(0, symbol, 1);
	symbol[1] = '\0';
	while (symbol[0] != '\n' && ft_strlen(*buf) < 5 && size != 0)
	{
		ft_strlcat(*buf, symbol, 5);
		size = read(0, symbol, 1);
	}
	return (size);
}

static void	follow_instructions(t_stack_elem **head_a)
{
	t_stack_elem	*head_b;
	char			buf[5];
	int				size;

	head_b = NULL;
	size = read_stdin(&buf);
	while (size != 0)
	{
		if (do_action(head_a, &head_b, buf) != 0)
		{
			free_stack(&head_b);
			write(2, "Error\n", 6);
			return ;
		}
		size = read_stdin(&buf);
	}
	if (is_not_finally_sorted(*head_a) || stack_size(head_b) > 0)
	{
		write(1, "KO\n", 3);
		free_stack(&head_b);
	}
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack_elem	*head_a;
	char			*str;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv[1]);
		argv = ft_split(str, ' ', &argc);
		free(str);
	}
	if (check_errors(argc, argv))
	{
		if (argv[0][0] == '!')
			free_array(argv);
		return (ft_error());
	}
	head_a = record_stack(argc, argv);
	if (check_uniq(head_a))
		return (case_uniq_nums(head_a, argv));
	follow_instructions(&head_a);
	free_stack(&head_a);
	if (argv[0][0] == '!')
		free_array(argv);
	return (0);
}
