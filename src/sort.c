/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:13:05 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 16:05:33 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	set_target(*a, *b, INT_MAX);
	set_cost(*a, *b);
	cheapest = select_cheapest_target(*b);
	if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		loop_rrr(cheapest, a, b);
	else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		loop_rr(cheapest, a, b);
	loop_rotate_a(cheapest, a);
	loop_rotate_b(cheapest, b);
	pa(a, b);
}

void	push_all_except_three(int size, t_stack **a, t_stack **b)
{
	int		blocks;
	int		current_block;
	int		pushed;
	t_range	range;

	current_block = 0;
	pushed = 0;
	blocks = set_blocks(size);
	while (pushed < size - 3)
	{
		range = set_range(current_block, size, blocks);
		if ((*a)->index >= range.min && (*a)->index <= range.max)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		if (pushed == range.max)
			current_block++;
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = find_max(*stack);
	if (*stack == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	sort(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*min;

	min = find_min(*a);
	size = ps_lstsize(*a);
	push_all_except_three(size, a, b);
	sort_three(a);
	while (*b)
		push_back(a, b);
	update_position(a);
	while (*a != min)
	{
		if (min->direction == UP)
			ra(a);
		else if (min->direction == DOWN)
			rra(a);
	}
}
