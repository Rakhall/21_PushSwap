/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:10:15 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 21:48:52 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int		stack_len(t_stack *a)
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

int		check_location(t_stack *b, int elem)
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

int		find_place(t_stack *a, t_stack *b, int index)
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

int		steps(int index, t_stack *a, t_stack *b)
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
		argc = str_arr_len(args);
		get_numbers(&a, argc, args);
		solve(&a, &b, &flags);
		freedom(a, b, flags, args);
	}
	else
		ft_putstr("usage: ./push_swap -[options] numbers list (n1 n2...)\n");
	return (0);
}
