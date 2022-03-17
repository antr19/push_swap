/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:26:56 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 17:50:20 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	d_len;
	int	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len < dstsize)
	{
		while (src[i] && (i + d_len) < (dstsize - 1))
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = '\0';
		return (d_len + s_len);
	}
	else
		return (dstsize + s_len);
}
