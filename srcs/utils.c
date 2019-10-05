/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:44:28 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 22:17:56 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void			read_numbers(t_stack **a, int argc, char **argv)
{
	long long int	temp;
	int				i;
	t_stack			*t;

	init(a, argc, argv);
	i = 0;
	t = *a;
	while (i < argc)
	{
		temp = atoll(argv[i]);
		if (!(number_validation(temp, t, *a)))
			validation_error(a, argv);
		else
		{
			(*a)->content = (int)temp;
			(*a) = (*a)->next;
		}
		i++;
	}
	i--;
	*a = t;
}

void			init(t_stack **a, int argc, char **argv)
{
	t_stack		*temp;
	t_stack		*new;
	int			i;

	if (!(int_array_validation(argc, argv)))
		validation_error(a, argv);
	i = 1;
	temp = *a;
	while (i < argc)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
			err();
		new->next = temp;
		temp = new;
		i++;
	}
	*a = temp;
}

void			operations(t_flags *flags)
{
	if (flags->c)
	{
		ft_putstr("Операций:");
		ft_putnbr(flags->nb);
		ft_putstr("\n");
	}
}

long long int	atoll(const char *str)
{
	int				neg;
	long long int	res;
	int				i;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t')
	|| (str[i] == '\r') || (str[i] == '\f') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + ((str[i] - '0') % 10);
		i++;
	}
	return (res * neg);
}
