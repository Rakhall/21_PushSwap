/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:17:18 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 19:52:18 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_stackfree(t_stack **stack)
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

void			freedom(t_stack *a, t_stack *b, t_flags *flags, char **args)
{
	ft_stackfree(&a);
	ft_stackfree(&b);
	free(flags);
	ft_strarrayfree(args);
}

void	display_stacks(t_stack *a, t_stack *b)
{
	t_stack			*temp;
	t_stack			*temp_b;

	temp = a;
	temp_b = b;
	//ft_printf("---------------------------------------------------\n");
	//ft_printf(" Stack A :");
	ft_putstr("---------------------------------------------------\n");
	ft_putstr(" Stack A :");
	while (temp)
	{
		ft_putnbr(temp->content);
		//ft_printf(" |%d|", temp->content);
		temp = temp->next;
	}
	ft_putstr("\n Stack B :");
	//ft_printf("\n Stack B :");
	while (temp_b)
	{
		ft_putnbr(temp_b->content);
		//ft_printf(" |%d|", temp_b->content);
		temp_b = temp_b->next;
	}
	ft_putstr("\n---------------------------------------------------\n");
	//ft_printf("\n---------------------------------------------------\n");
}
