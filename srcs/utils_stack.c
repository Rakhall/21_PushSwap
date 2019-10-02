/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:17:18 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:13:33 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_stack		*ft_stacknew(int content)
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

void		freedom(t_stack *a, t_stack *b, t_flags *flags, char **args)
{
	stack_free(&a);
	stack_free(&b);
	free(flags);
	str_arr_free(args);
}

void		print(t_stack *a, t_stack *b)
{
	t_stack			*temp;
	t_stack			*temp_b;

	temp = a;
	temp_b = b;
	ft_putstr("_____________________________________________________________________\n");
	ft_putstr("stack A :");
	while (temp)
	{
		write(1, " ", 1);
		ft_putnbr(temp->content);
		temp = temp->next;
	}
	ft_putstr("\nstack B :");
	while (temp_b)
	{
		write(1, " ", 1);
		ft_putnbr(temp_b->content);
		temp_b = temp_b->next;
	}
	ft_putstr("\n");
}
