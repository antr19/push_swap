/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:42 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 17:15:42 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
