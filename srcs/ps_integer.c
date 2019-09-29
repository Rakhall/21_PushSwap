/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_int_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:19:37 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 20:21:40 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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

int				last_val(t_stack *b)
{
	t_stack *temp;

	temp = b;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}
