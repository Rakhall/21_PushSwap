/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:44:28 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 18:13:44 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		push(t_stack **a, t_stack **b)
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

static void		revrotate(t_stack **stack)
{
	t_stack		*inc;
	int			prev_c;
	int			cur_c;

	if (*stack && (*stack)->next)
	{
		inc = *stack;
		prev_c = inc->content;
		while (inc->next)
		{
			cur_c = inc->next->content;
			inc->next->content = prev_c;
			prev_c = cur_c;
			inc = inc->next;
		}
		(*stack)->content = prev_c;
	}
}

static void		rotate(t_stack **stack)
{
	t_stack		*temp;
	int			first;

	if (*stack)
	{
		temp = *stack;
		first = (*stack)->content;
		while (temp->next)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
	}
}

static void		swap(t_stack **stack)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
}

t_stack	*ft_stacknew(int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int		check_for_flags(char **str, t_flags **flags)
{
	if (!(*flags))
	{
		if (!((*flags) = (t_flags *)malloc(sizeof(t_flags))))
			cmn_error();
		(*flags)->count = 0;
		(*flags)->v = 0;
		if (ft_strcmp(str[1], "-t") == 0)
		{
			(*flags)->count = 1;
			(*flags)->nb = 0;
		}
		if (ft_strcmp(str[1], "-v") == 0)
			(*flags)->v = 1;
		if (str[2])
		{
			if (ft_strcmp(str[2], "-t") == 0 && (*flags)->count == 0)
			{
				(*flags)->count = 1;
				(*flags)->nb = 0;
			}
			if (ft_strcmp(str[2], "-v") == 0 && (*flags)->v == 0)
				(*flags)->v = 1;
		}
	}
	return ((*flags)->v + (*flags)->count);
}

char	**ft_strarrdup(char **str)
{
	char	**res;
	size_t	len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	if (!(res = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int		ft_strarraylen(char **array)
{
	int res;

	res = 0;
	while (array[res])
		res++;
	return (res);
}

void			get_numbers(t_stack **a, int argc, char **argv)
{
	long long int	temp;
	int				i;
	t_stack			*t;

	init_list(a, argc, argv);
	i = 0;
	t = *a;
	while (i < argc)
	{
		temp = ft_atoll(argv[i]);
		if (!(check_valid_nb(temp, t, *a)))
			mult_error(a, argv);
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

void			init_list(t_stack **a, int argc, char **argv)
{
	t_stack		*temp;
	t_stack		*new;
	int			i;

	if (!(check_valid_args(argc, argv)))
		mult_error(a, argv);
	i = 1;
	temp = *a;
	while (i < argc)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
			cmn_error();
		new->next = temp;
		temp = new;
		i++;
	}
	*a = temp;
}

int			check_valid_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	mult_error(t_stack **a, char **args)
{
	ft_stackfree(a);
	ft_strarrayfree(args);
	write(2, "Error : invalid parameters\n", 27);
	exit(1);
}

void	ft_stackfree(t_stack **stack)
{
	t_stack *next;
	t_stack *cur;

	if (stack)
	{
		cur = *stack;
		while (cur != NULL)
		{
			next = cur->next;
			cur->content = 0;
			free(cur);
			cur = next;
		}
		*stack = NULL;
	}
}

void	ft_strarrayfree(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	cmn_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int			check_valid_nb(long long int nb, t_stack *t, t_stack *a)
{
	t_stack	*temp;

	temp = t;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (temp != a)
	{
		if (temp->content == (int)nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			check_sort(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void			pa(t_stack **a, t_stack **b, t_flags **flags)
{
	push(b, a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			pb(t_stack **a, t_stack **b, t_flags **flags)
{
	push(a, b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			sa(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			sb(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			ra(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rb(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rra(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rrb(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	display_stacks(t_stack *a, t_stack *b)
{
	t_stack			*temp;
	t_stack			*temp_b;

	temp = a;
	temp_b = b;
	//ft_printf("---------------------------------------------------\n");
	//ft_printf(" Stack A :");
	ft_putstr("---------------------------------------------------\n");
	ft_putstr(" Stack A :");
	while (temp)
	{
		ft_putnbr(temp->content);
		//ft_printf(" |%d|", temp->content);
		temp = temp->next;
	}
	ft_putstr("\n Stack B :");
	//ft_printf("\n Stack B :");
	while (temp_b)
	{
		ft_putnbr(temp_b->content);
		//ft_printf(" |%d|", temp_b->content);
		temp_b = temp_b->next;
	}
	ft_putstr("\n---------------------------------------------------\n");
	//ft_printf("\n---------------------------------------------------\n");
}

void			ss(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	swap(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rr(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	rotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rrr(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	revrotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void	do_count(t_flags *flags)
{
	if (flags->count) {
		ft_putstr("== TOTAL MOVES : ");
		ft_putnbr(flags->nb);
		ft_putstr(" ==\n");
		//ft_printf("== TOTAL MOVES : %d ==\n", flags->nb);
	}
}

void			freedom(t_stack *a, t_stack *b, t_flags *flags, char **args)
{
	ft_stackfree(&a);
	ft_stackfree(&b);
	free(flags);
	ft_strarrayfree(args);
}

long long int	ft_atoll(const char *str)
{
	int				neg;
	long long int	res;
	int				i;

	neg = 1;
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
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

int		ft_isspace(int c)
{
	return ((c == '\t') || (c == '\v')
			|| (c == '\n') || (c == '\r')
			|| (c == '\f') || (c == ' '));
}
