# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 22:14:41 by sstannis          #+#    #+#              #
#    Updated: 2019/09/29 18:05:27 by sstannis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

CH_SRCS = srcs/checker.c srcs/utils.c
		 
PS_SRCS = srcs/push_swap.c srcs/utils.c

INC = ft_push_swap.h

CH_OBJS = $(CH_SRCS:.c=.o)
PS_OBJS = $(PS_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH):
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME_CH) -Iinclude $(LIBFT)/libft.a $(CH_SRCS)
	@echo "\033[1;34mchecker\033[1;32m...compiled\t✓\033[0m"

$(NAME_PS):
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME_PS) -Iinclude $(LIBFT)/libft.a $(PS_SRCS)
	@echo "\033[1;34mpush_swap\033[1;32m..compiled\t✓\033[0m"

clean:
	@rm -rf $(CH_OBJS) $(PS_OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME_PS) $(NAME_CH)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m files deleted\t\t\033[1;31m✓\033[0m"

re: fclean all