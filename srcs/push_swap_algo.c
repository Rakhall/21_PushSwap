/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:13:37 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 20:14:35 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	solve(t_stack **a, t_stack **b, t_flags **flags)
{
	int		len;

	len = stack_len(*a);
	if (check_sort(*a) == 0)
	{
		if (len <= 3)
			solve_three(a, b, flags);
		else if (len < 8)
			solve_small_len(a, b, flags);
		else
			solve_big_len(a, b, flags);
	}
}

void			solve_three(t_stack **a, t_stack **b, t_flags **flags)
{
	t_stack		*temp;
	int			min;

	if (check_sort(*a) == 0)
	{
		temp = *a;
		min = min_val(*a);
		if (stack_len(*a) == 2)
		{
			sa(a, b, flags);
			ft_putstr("sa\n");
		}
		else if (temp->content == min)
		{
			rra(a, b, flags);
			ft_putstr("rra\n");
			sa(a, b, flags);
			ft_putstr("sa\n");
		}
		else if (temp->next->content == min)
			three_min_sec(a, b, flags);
		else if (temp->next->next->content == min)
			three_min_third(a, b, flags);
	}
}

void				solve_small_len(t_stack **a, t_stack **b, t_flags **flags)
{
	int min;

	while (check_sort(*a) == 0 || *b)
	{
		if (stack_len(*a) == 3)
			solve_three(a, b, flags);
		min = min_val(*a);
		while ((*a)->content != min)
			min_to_top(a, b, flags);
		if (check_sort(*a) == 0)
		{
			pb(a, b, flags);
			ft_putstr("pb\n");
		}
		else
		{
			while (*b)
			{
				pa(a, b, flags);
				ft_putstr("pa\n");
			}
		}
	}
	do_count(*flags);
}

void				solve_big_len(t_stack **a, t_stack **b, t_flags **flags)
{
	int		len;
	t_data	*data;

	if (check_sort(*a) == 0)
	{
		len = stack_len(*a);
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			cmn_error();
		while (stack_len(*a) != 1)
			min_steps(a, b, data, flags);
		order_b(a, b, flags);
		push_back_to_a(a, b, flags);
		free(data);
		do_count(*flags);
	}
}
