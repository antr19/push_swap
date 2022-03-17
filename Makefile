# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 17:55:58 by mikabuto          #+#    #+#              #
#    Updated: 2022/03/07 17:55:58 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
B_NAME = checker

SRCS =	actions2.c errors.c find_best_root.c ft_split.c \
		main.c stack_sort.c stack_utils.c actions.c \
		array_utils.c execute_rotations.c ft_atoi.c \
		ft_strjoin.c stack_sort2.c final_sorting.c \
		errors2.c

B_SRCS = checker_bonus.c ft_strncmp.c errors.c \
		actions.c actions2.c stack_utils.c \
		ft_split.c ft_strjoin.c ft_atoi.c \
		ft_strlcat.c errors2.c

HEAD =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

CC = 	cc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(FLAGS) $(B_OBJS) -o $(B_NAME)

.c.o: $(HEAD)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS} $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus