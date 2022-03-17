/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:06:43 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/05 13:49:56 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	start_recording_index(int n, char const *str, char c)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (k < n)
	{
		while (str[j] && str[j] == c)
			j++;
		while (str[j] && str[j] != c)
			j++;
		k++;
	}
	return (j);
}

static char	*get_word(char const *str, char c, int n)
{
	int		i;
	int		j;
	int		word_len;
	char	*word;

	word_len = 0;
	j = start_recording_index(n, str, c);
	while (str[j] && str[j] == c)
		j++;
	while (str[j++] && str[j - 1] != c)
		word_len++;
	word = (char *)malloc(word_len + 1);
	if (!word)
		return (NULL);
	i = -1;
	j = j - word_len - 1;
	while (++i < word_len)
		word[i] = str[j++];
	word[i] = '\0';
	return (word);
}

static int	ft_words_num(char const *str, char c)
{
	int	words_num;
	int	i;

	i = 0;
	words_num = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		words_num++;
	}
	return (words_num);
}

char	**free_array(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		words[i] = NULL;
		++i;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c, int *words_num)
{
	int		i;
	char	**words;

	if (!s)
		return (NULL);
	*words_num = ft_words_num(s, c);
	words = (char **)malloc((*words_num + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = -1;
	while (++i < *words_num)
	{
		words[i] = get_word(s, c, i);
		if (!words[i])
			return (free_array(words));
	}
	words[i] = NULL;
	return (words);
}
