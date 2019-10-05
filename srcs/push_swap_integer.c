/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:19:37 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 21:18:33 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				int_min(t_stack *a)
{
	int			i;
	t_stack		*temp;

	temp = a;
	i = temp->content;
	while (temp)
	{
		if (temp->content < i)
			i = temp->content;
		temp = temp->next;
	}
	return (i);
}

int				int_max(t_stack *a)
{
	int			i;
	t_stack		*temp;

	temp = a;
	i = temp->content;
	while (temp)
	{
		if (temp->content > i)
			i = temp->content;
		temp = temp->next;
	}
	return (i);
}

int				max_index(t_stack *a)
{
	int			i;
	int			max;
	t_stack		*temp;

	temp = a;
	max = int_max(a);
	i = 0;
	while (temp)
	{
		if (temp->content == max)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

int				min_index(t_stack *a)
{
	int			i;
	int			min;
	t_stack		*temp;

	temp = a;
	min = int_min(a);
	i = 0;
	while (temp)
	{
		if (temp->content == min)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

int				last_number(t_stack *b)
{
	t_stack *temp;

	temp = b;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}
