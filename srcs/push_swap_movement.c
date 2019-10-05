/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:26:00 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 22:21:34 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	three_min_sec(t_stack **a, t_stack **b, t_flags **flags)
{
	if ((*a)->content > (*a)->next->next->content)
	{
		ra(a, b, flags);
		ft_putstr("ra\n");
	}
	else
	{
		sa(a, b, flags);
		ft_putstr("sa\n");
	}
}

void	three_min_third(t_stack **a, t_stack **b, t_flags **flags)
{
	if ((*a)->content > (*a)->next->content)
	{
		sa(a, b, flags);
		ft_putstr("sa\n");
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
	else
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}

void	min_to_top(t_stack **a, t_stack **b, t_flags **flags)
{
	int index;

	index = min_index(*a);
	if (index <= (stack_len(*a) / 2))
	{
		ra(a, b, flags);
		ft_putstr("ra\n");
	}
	else if (index > (stack_len(*a) / 2))
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}

void	order_b(t_stack **a, t_stack **b, t_flags **flags)
{
	if (max_index(*b) > stack_len(*b) / 2)
	{
		while ((*b)->content != int_max(*b))
		{
			rrb(a, b, flags);
			ft_putstr("rrb\n");
		}
	}
	else
	{
		while ((*b)->content != int_max(*b))
		{
			rb(a, b, flags);
			ft_putstr("rb\n");
		}
	}
}

void	push_to_a(t_stack **a, t_stack **b, t_flags **flags)
{
	while (*b && (*b)->content > last_number(*a))
	{
		pa(a, b, flags);
		ft_putstr("pa\n");
	}
	if (*b)
	{
		if (stack_len(*a) != 1)
		{
			rra(a, b, flags);
			ft_putstr("rra\n");
		}
		while (*b)
		{
			pa(a, b, flags);
			ft_putstr("pa\n");
		}
	}
	if ((*a)->content > last_number(*a))
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}
