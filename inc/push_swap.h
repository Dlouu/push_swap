/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:19:01 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 17:13:42 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 1
# define FAILURE 0

// ROTATION DIRECTION
// rotate:  Shift up all elements of stack a by 1.
# define UP -1
// reverse rotate: Shift down all elements of stack a by 1.
# define DOWN 1

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "./../libft/inc/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	int				direction;
	int				position;
	int				best;
	int				cost;
	int				cost_a;
	int				cost_b;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_range
{
	int				min;
	int				max;
}					t_range;

//push_swap
int		parsing(int nb, char **numbers);
t_stack	*create_stack(int n, char **numbers);
void	set_index(int n, char **nbr, t_stack **stack);
char	*sort_index(int n, char **nbr);
void	select_sort(t_stack **a, t_stack **b);

//sort
void	sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void	push_all_except_three(int size, t_stack **a, t_stack **b);
void	set_target(t_stack *a, t_stack *b, int best);
void	set_best_target(int best, t_stack *best_target, t_stack *b, t_stack *a);
void	set_cost(t_stack *a, t_stack *b);
t_stack	*select_cheapest_target(t_stack *b);
void	push_back(t_stack **a, t_stack **b);

//operations
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	loop_rrr(t_stack *cheapest, t_stack **a, t_stack **b);
void	loop_rr(t_stack *cheapest, t_stack **a, t_stack **b);
void	loop_rotate_a(t_stack *cheapest, t_stack **a);
void	loop_rotate_b(t_stack *cheapest, t_stack **b);

//utils
void	clean_exit(int success, t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		set_blocks(int size);
t_range	set_range(int i, int size, int blocks);
void	update_position(t_stack **stack);

//utils_lst
t_stack	*ps_lstnew(int number);
void	ps_lstadd(t_stack **lst, t_stack *new);
int		ps_lstsize(t_stack *lst);
void	ps_lstclear(t_stack **lst, void (*del)(void *));

#endif
