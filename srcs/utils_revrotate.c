/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:08:17 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:15:10 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	revrotate(t_stack **stack)
{
	t_stack		*inc;
	int			prev_c;
	int			cur_c;

	if (*stack && (*stack)->next)
	{
		inc = *stack;
		prev_c = inc->content;
		while (inc->next)
		{
			cur_c = inc->next->content;
			inc->next->content = prev_c;
			prev_c = cur_c;
			inc = inc->next;
		}
		(*stack)->content = prev_c;
	}
}

void	rra(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	rrb(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	rrr(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	revrotate(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
