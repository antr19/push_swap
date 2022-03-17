/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:36:57 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/05 14:17:12 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (ret);
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		s1_len;
	int		s2_len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	s = (char *)malloc(s1_len + s2_len + 1);
	if (!s)
		return (NULL);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
