/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:05:52 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:15:29 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack		*temp;
	int			first;

	if (*stack)
	{
		temp = *stack;
		first = (*stack)->content;
		while (temp->next)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
	}
}

void	ra(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	rb(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	rr(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	rotate(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
