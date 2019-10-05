/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:15:21 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/03 22:35:02 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_data
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				min_index;
	int				min_steps;
	int				i;
}					t_data;

typedef struct		s_flags
{
	int				nb;
	char			v;
	char			c;
}					t_flags;

void				swap(t_stack **stack);
void				sa(t_stack **a, t_stack **b, t_flags **flags);
void				sb(t_stack **a, t_stack **b, t_flags **flags);
void				ss(t_stack **a, t_stack **b, t_flags **flags);
void				push(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b, t_flags **flags);
void				pb(t_stack **a, t_stack **b, t_flags **flags);
void				revrotate(t_stack **stack);
void				rra(t_stack **a, t_stack **b, t_flags **flags);
void				rrb(t_stack **a, t_stack **b, t_flags **flags);
void				rrr(t_stack **a, t_stack **b, t_flags **flags);
void				rotate(t_stack **stack);
void				ra(t_stack **a, t_stack **b, t_flags **flags);
void				rb(t_stack **a, t_stack **b, t_flags **flags);
void				rr(t_stack **a, t_stack **b, t_flags **flags);
t_stack				*new_stack(int content);
void				stack_free(t_stack **stack);
void				final_free(t_stack *a, t_stack *b, t_flags *flags,
	char **nums);
void				print(t_stack *a, t_stack *b);
int					check_stack_sort(t_stack *a);
int					number_validation(long long int nb, t_stack *t, t_stack *a);
int					int_array_validation(int argc, char **argv);
int					read_flags(char **str, t_flags **flags);
char				**str_arr_dup(char **str);
int					str_arr_len(char **array);
void				str_arr_free(char **strs);
void				validation_error(t_stack **a, char **nums);
void				err();
void				rotations(t_stack **a, t_stack **b, t_data *data,
	t_flags **flags);
void				rot(t_stack **a, t_stack **b, t_data *data,
	t_flags **flags);
void				revrot(t_stack **a, t_stack **b, t_data *data,
	t_flags **flags);
void				min_steps(t_stack **a, t_stack **b, t_data *data,
	t_flags **flags);
void				three_min_sec(t_stack **a, t_stack **b, t_flags **flags);
void				three_min_third(t_stack **a, t_stack **b, t_flags **flags);
void				min_to_top(t_stack **a, t_stack **b, t_flags **flags);
void				order_b(t_stack **a, t_stack **b, t_flags **flags);
void				push_to_a(t_stack **a, t_stack **b, t_flags **flags);
int					int_min(t_stack *a);
int					int_max(t_stack *a);
int					max_index(t_stack *a);
int					min_index(t_stack *a);
int					last_number(t_stack *b);
void				start(t_stack **a, t_stack **b, t_flags **flags);
void				algo_three(t_stack **a, t_stack **b, t_flags **flags);
void				algo_seven(t_stack **a, t_stack **b, t_flags **flags);
void				algo(t_stack **a, t_stack **b, t_flags **flags);
void				read_numbers(t_stack **a, int argc, char **argv);
void				init(t_stack **a, int argc, char **argv);
void				operations(t_flags *flags);
long long int		atoll(const char *str);
int					stack_len(t_stack *a);
int					scope(t_stack *a, t_stack *b, int index);
int					steps(int index, t_stack *a, t_stack *b);

#endif
