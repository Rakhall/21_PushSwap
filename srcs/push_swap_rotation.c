/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:22:36 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 20:29:59 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	rotations(t_stack **a, t_stack **b, t_data *data, t_flags **flags)
{
	data->ra = 0;
	data->rb = 0;
	data->rra = 0;
	data->rrb = 0;
	if (data->min_index <= stack_len(*a) / 2)
		data->ra = data->min_index;
	else
		data->rra = stack_len(*a) - data->min_index;
	if (data->place <= stack_len(*b) / 2)
		data->rb = (data->min_steps - data->rra - data->ra - 1);
	else
		data->rrb = (data->min_steps - data->rra - data->ra - 1);
	rot(a, b, data, flags);
	revrot(a, b, data, flags);
	pb(a, b, flags);
	ft_putstr("pb\n");
}

void	rot(t_stack **a, t_stack **b, t_data *data, t_flags **flags)
{
	while (data->ra > 0 && data->rb > 0)
	{
		rr(a, b, flags);
		ft_putstr("rr\n");
		(data->ra)--;
		(data->rb)--;
	}
	while (data->ra > 0)
	{
		ra(a, b, flags);
		ft_putstr("ra\n");
		(data->ra)--;
	}
	while (data->rb > 0)
	{
		rb(a, b, flags);
		ft_putstr("rb\n");
		(data->rb)--;
	}
}

void	revrot(t_stack **a, t_stack **b, t_data *data, t_flags **flags)
{
	while (data->rra > 0 && data->rrb > 0)
	{
		rrr(a, b, flags);
		ft_putstr("rrr\n");
		(data->rra)--;
		(data->rrb)--;
	}
	while (data->rra > 0)
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
		(data->rra)--;
	}
	while (data->rrb > 0)
	{
		rrb(a, b, flags);
		ft_putstr("rrb\n");
		(data->rrb)--;
	}
}

void		min_steps(t_stack **a, t_stack **b, t_data *data, t_flags **flags)
{
	int			i;
	int			step_num;

	i = 0;
	data->min_steps = 2147483647;
	data->min_index = 2147483647;
	while (i < stack_len(*a))
	{
		step_num = steps(i, *a, *b);
		if (step_num < data->min_steps)
		{
			data->min_steps = step_num;
			data->min_index = i;
		}
		i++;
	}
	data->place = find_place(*a, *b, data->min_index);
	rotations(a, b, data, flags);
}
