/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:15:21 by sstannis          #+#    #+#             */
/*   Updated: 2019/10/02 22:23:41 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_data
{
	int				min_index;
	int				place;
	int				min_steps;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
}					t_data;

typedef struct		s_flags
{
	char			count;
	int				nb;
	char			v;
}					t_flags;

typedef struct	s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

void			swap(t_stack **stack);
void			sa(t_stack **a, t_stack **b, t_flags **flags);
void			sb(t_stack **a, t_stack **b, t_flags **flags);
void			ss(t_stack **a, t_stack **b, t_flags **flags);
void			push(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b, t_flags **flags);
void			pb(t_stack **a, t_stack **b, t_flags **flags);
void			revrotate(t_stack **stack);
void			rra(t_stack **a, t_stack **b, t_flags **flags);
void			rrb(t_stack **a, t_stack **b, t_flags **flags);
void			rrr(t_stack **a, t_stack **b, t_flags **flags);
void			rotate(t_stack **stack);
void			ra(t_stack **a, t_stack **b, t_flags **flags);
void			rb(t_stack **a, t_stack **b, t_flags **flags);
void			rr(t_stack **a, t_stack **b, t_flags **flags);
t_stack			*ft_stacknew(int content);
void			stack_free(t_stack **stack);
void			freedom(t_stack *a, t_stack *b, t_flags *flags, char **args);
void			print(t_stack *a, t_stack *b);
int				check_stack_sort(t_stack *a);
int				check_valid_nb(long long int nb, t_stack *t, t_stack *a);
int				check_valid_args(int argc, char **argv);
int				check_for_flags(char **str, t_flags **flags);
char			**ft_strarrdup(char **str);
int				str_arr_len(char **array);
void			str_arr_free(char **strs);
void			mult_error(t_stack **a, char **args);
void			cmn_error(void);
void			rotations(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
void			rot(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
void			revrot(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
void			min_steps(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
void			three_min_sec(t_stack **a, t_stack **b, t_flags **flags);
void			three_min_third(t_stack **a, t_stack **b, t_flags **flags);
void			min_to_top(t_stack **a, t_stack **b, t_flags **flags);
void			order_b(t_stack **a, t_stack **b, t_flags **flags);
void			push_back_to_a(t_stack **a, t_stack **b, t_flags **flags);
int				min_val(t_stack *a);
int				max_val(t_stack *a);
int				max_index(t_stack *a);
int				min_index(t_stack *a);
int				last_val(t_stack *b);
void			solve(t_stack **a, t_stack **b, t_flags **flags);
void			solve_three(t_stack **a, t_stack **b, t_flags **flags);
void			solve_small_len(t_stack **a, t_stack **b, t_flags **flags);
void			solve_big_len(t_stack **a, t_stack **b, t_flags **flags);
void			get_numbers(t_stack **a, int argc, char **argv);
void			init_list(t_stack **a, int argc, char **argv);
void			do_count(t_flags *flags);
long long int	atoll(const char *str);
int				stack_len(t_stack *a);
int				find_place(t_stack *a, t_stack *b, int index);
int				steps(int index, t_stack *a, t_stack *b);


#endif
