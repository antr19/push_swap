/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:06:11 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/05 13:06:11 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_elem
{
	struct s_stack_elem	*next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					order;
}	t_stack_elem;

//	record_stack.c
t_stack_elem	*record_stack(int argc, char **argv);

//	ft_strjoin.c
int				ft_strlen(char *s);
char			*ft_strjoin(char const *s1, char const *s2);

//	ft_split.c
char			**free_array(char **words);
char			**ft_split(char const *s, char c, int *words_num);

//	ft_atoi.c
int				ft_isdigit(int c);
long long int	ft_atoi(const char *str);

//	errors.c
int				ft_error(void);
int				check_uniq(t_stack_elem *head);
int				check_errors(int argc, char **argv);

//	errors2.c
int				case_uniq_nums(t_stack_elem *head_a, char **argv);

//	stack_utils.c
int				stack_size(t_stack_elem *lst);
t_stack_elem	*create_elem(int value);
void			push_back(t_stack_elem **head, t_stack_elem *new);
t_stack_elem	*record_stack(int argc, char **argv);
void			free_stack(t_stack_elem **head);

//	stack_sort.c
int				sorted(t_stack_elem *head);
void			define_order(t_stack_elem *head, int *arr);
void			stack_sort(t_stack_elem **head_a);

//	array_utils.c
void			array_sort(int *arr, int size);

//	actions.c
void			swap(t_stack_elem **head, char stack_name, int output);
void			double_swap(t_stack_elem **head_a, t_stack_elem **head_b, \
				int output);
void			rotate(t_stack_elem **head, char stack_name, int output);
void			double_rotate(t_stack_elem **head_a, t_stack_elem **head_b, \
				int output);
void			push_to_other_stack(t_stack_elem **from, t_stack_elem **to, \
				char stack_name, int output);

//	actions2.c
void			rev_rotate(t_stack_elem **head, char stack_name, int output);
void			double_rev_rotate(t_stack_elem **head_a, t_stack_elem **head_b, \
				int output);

//	stack_sort2.c
void			final_sort(t_stack_elem **head);
void			push_to_a(t_stack_elem **head_a, t_stack_elem **head_b);

//	find_best_root.c
t_stack_elem	*find_cheapest_elem(t_stack_elem *head, int *ttype);

//	execute_rotations.c
void			execute_rotations(t_stack_elem **head_a, t_stack_elem **head_b, \
				t_stack_elem *elem, int ttype);

//	ft_strncmp.c
int				ft_strncmp(const char *s1, const char *s2, int n);

//	ft_strlcat.c
int				ft_strlcat(char *dst, char *src, int dstsize);

#endif