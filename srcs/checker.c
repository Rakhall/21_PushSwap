/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:04:28 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 22:41:13 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	inst_error(t_stack **a, t_stack **b, char *line, t_flags **flags)
{
	free(*flags);
	free(line);
	stack_free(a);
	stack_free(b);
	write(2, "Error : invalid instruction\n", 28);
	exit(1);
}

void	run(char *line, t_stack **a, t_stack **b, t_flags **flags)
{
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			ft_strcmp(line, "pa") == 0 ? pa(a, b, flags) : pb(a, b, flags);
		else if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0)
			ft_strcmp(line, "sa") == 0 ? sa(a, b, flags) : sb(a, b, flags);
		else if (ft_strcmp(line, "ss") == 0)
			ss(a, b, flags);
		else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0)
			ft_strcmp(line, "ra") == 0 ? ra(a, b, flags) : rb(a, b, flags);
		else if (ft_strcmp(line, "rr") == 0)
			rr(a, b, flags);
		else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0)
			ft_strcmp(line, "rra") == 0 ? rra(a, b, flags) : rrb(a, b, flags);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(a, b, flags);
		else
			inst_error(a, b, line, flags);
		ft_strclr(line);
		free(line);
	}
	if (check_stack_sort(*a))
		operations(*flags);
	ft_strclr(line);
	free(line);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	char		**array;
	t_flags		*flags;

	if (argc > 1)
	{
		a = new_stack(0);
		b = NULL;
		line = NULL;
		if (argc == 2 + read_flags(argv, &flags))
			array = ft_strsplit(argv[1 + read_flags(argv, &flags)], ' ');
		else
			array = str_arr_dup(&argv[1 + read_flags(argv, &flags)]);
		read_numbers(&a, str_arr_len(array), array);
		run(line, &a, &b, &flags);
		ft_putstr((check_stack_sort(a) && !b) ? "OK\n" : "KO\n");
		final_free(a, b, flags, array);
	}
	else
		ft_putstr("usage: ./checker -[options] numbers list (n1 n2...)\n");
	return (0);
}
