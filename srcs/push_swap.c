/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:10:15 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 18:10:23 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		three_min_sec(t_stack **a, t_stack **b, t_flags **flags)
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

static void		three_min_third(t_stack **a, t_stack **b, t_flags **flags)
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

static void			min_to_top(t_stack **a, t_stack **b, t_flags **flags)
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

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	t_flags		*flags;
	int			cflags;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		cflags = check_for_flags(argv, &flags);
		if (argc == 2 + cflags)
			args = ft_strsplit(argv[1 + cflags], ' ');
		else
			args = ft_strarrdup(&argv[1 + cflags]);
		argc = ft_strarraylen(args);
		get_numbers(&a, argc, args);
		solve(&a, &b, &flags);
		freedom(a, b, flags, args);
	}
	else
	//	ft_printf("usage: ./push_swap -[options] numbers list (n1 n2...)\n");
		ft_putstr("usage: ./push_swap -[options] numbers list (n1 n2...)\n");
	return (0);
}

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

int				stack_len(t_stack *a)
{
	int			res;
	t_stack		*temp;

	if (!a)
		return (0);
	res = 0;
	temp = a;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return (res);
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

int				min_val(t_stack *a)
{
	int			res;
	t_stack		*temp;

	temp = a;
	res = temp->content;
	while (temp)
	{
		if (temp->content < res)
			res = temp->content;
		temp = temp->next;
	}
	return (res);
}

int				min_index(t_stack *a)
{
	int			res;
	int			min;
	t_stack		*temp;

	temp = a;
	min = min_val(a);
	res = 0;
	while (temp)
	{
		if (temp->content == min)
			return (res);
		res++;
		temp = temp->next;
	}
	return (-1);
}

int				max_val(t_stack *a)
{
	int			res;
	t_stack		*temp;

	temp = a;
	res = temp->content;
	while (temp)
	{
		if (temp->content > res)
			res = temp->content;
		temp = temp->next;
	}
	return (res);
}

int				last_val(t_stack *b)
{
	t_stack *temp;

	temp = b;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}

int				max_index(t_stack *a)
{
	int			res;
	int			max;
	t_stack		*temp;

	temp = a;
	max = max_val(a);
	res = 0;
	while (temp)
	{
		if (temp->content == max)
			return (res);
		res++;
		temp = temp->next;
	}
	return (-1);
}



int			find_place(t_stack *a, t_stack *b, int index)
{
	int			i;
	int			res;
	int			elem;
	t_stack		*temp;

	i = 0;
	temp = a;
	while (i++ < index)
		temp = temp->next;
	elem = temp->content;
	i = 0;
	res = -1;
	if (stack_len(b) == 0)
		return (0);
	else if (elem < min_val(b))
		return (max_index(b));
	else if (elem > max_val(b))
		return (max_index(b));
	else
		res = check_location(b, elem);
	return (res);
}

int			check_location(t_stack *b, int elem)
{
	int			i;
	int			res;
	t_stack		*temp;

	i = 0;
	temp = b;
	while (i < stack_len(b) - 1 && temp && temp->next)
	{
		if (elem < temp->content && elem > temp->next->content)
			res = i + 1;
		i++;
		temp = temp->next;
	}
	return (res);
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

int			steps(int index, t_stack *a, t_stack *b)
{
	int		steps;
	int		b_middle;
	int		place;

	steps = 0;
	b_middle = 0;
	place = find_place(a, b, index);
	if (index > 0 && index <= stack_len(a) / 2)
		steps += index;
	else if (index != 0)
		steps += stack_len(a) - index;
	steps++;
	b_middle = stack_len(b) / 2;
	if (place <= b_middle)
		steps += place;
	else
		steps += stack_len(b) - place;
	return (steps);
}

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

void				order_b(t_stack **a, t_stack **b, t_flags **flags)
{
	if (max_index(*b) > stack_len(*b) / 2)
	{
		while ((*b)->content != max_val(*b))
		{
			rrb(a, b, flags);
			ft_putstr("rrb\n");
		}
	}
	else
	{
		while ((*b)->content != max_val(*b))
		{
			rb(a, b, flags);
			ft_putstr("rb\n");
		}
	}
}

void				push_back_to_a(t_stack **a, t_stack **b, t_flags **flags)
{
	while (*b && (*b)->content > last_val(*a))
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
	if ((*a)->content > last_val(*a))
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}
