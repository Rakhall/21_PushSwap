/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:11:55 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:15:45 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	swap(t_stack **stack)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
}

void	sa(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	sb(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	ss(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	swap(b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
