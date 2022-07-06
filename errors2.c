/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:31:52 by fmarsha           #+#    #+#             */
/*   Updated: 2022/03/17 16:31:54 by fmarsha          ###   ########.fr       */
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
