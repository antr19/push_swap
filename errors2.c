/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:52:15 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 17:52:30 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_uniq_nums(t_stack_elem *head_a, char **argv)
{
	free_stack(&head_a);
	if (argv[0][0] == '!')
		free_array(argv);
	return (ft_error());
}
