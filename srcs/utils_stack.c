/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:17:18 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 22:30:53 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_stack		*new_stack(int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void		stack_free(t_stack **stack)
{
	t_stack *next;
	t_stack *cur;

	if (stack)
	{
		cur = *stack;
		while (cur != NULL)
		{
			next = cur->next;
			cur->content = 0;
			free(cur);
			cur = next;
		}
		*stack = NULL;
	}
}

void		final_free(t_stack *a, t_stack *b, t_flags *flags, char **nums)
{
	stack_free(&a);
	stack_free(&b);
	free(flags);
	str_arr_free(nums);
}

void		print(t_stack *a, t_stack *b)
{
	t_stack			*ta;
	t_stack			*tb;

	ta = a;
	tb = b;
	ft_putstr("______________________________________________________\n");
	ft_putstr("stack A :");
	while (ta)
	{
		write(1, " ", 1);
		ft_putnbr(ta->content);
		ta = ta->next;
	}
	ft_putstr("\nstack B :");
	while (tb)
	{
		write(1, " ", 1);
		ft_putnbr(tb->content);
		tb = tb->next;
	}
	ft_putstr("\n");
}
