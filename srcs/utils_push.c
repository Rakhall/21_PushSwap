/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:01:37 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:23:42 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*a)
	{
		temp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
	}
}

void	pa(t_stack **a, t_stack **b, t_flags **flags)
{
	push(b, a);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	pb(t_stack **a, t_stack **b, t_flags **flags)
{
	push(a, b);
	if ((*flags)->v)
		print(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
