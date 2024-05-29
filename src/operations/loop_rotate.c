/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:05:10 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 16:05:16 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	loop_rrr(t_stack *cheapest, t_stack **a, t_stack **b)
{
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		cheapest->cost_a++;
		cheapest->cost_b++;
		rrr(a, b);
	}
}

void	loop_rr(t_stack *cheapest, t_stack **a, t_stack **b)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		cheapest->cost_a--;
		cheapest->cost_b--;
		rr(a, b);
	}
}

void	loop_rotate_a(t_stack *cheapest, t_stack **a)
{
	while (cheapest->cost_a)
	{
		if (cheapest->cost_a > 0)
		{
			ra(a);
			cheapest->cost_a--;
		}
		else if (cheapest->cost_a < 0)
		{
			rra(a);
			cheapest->cost_a++;
		}
	}
}

void	loop_rotate_b(t_stack *cheapest, t_stack **b)
{
	while (cheapest->cost_b)
	{
		if (cheapest->cost_b > 0)
		{
			rb(b);
			cheapest->cost_b--;
		}
		else if (cheapest->cost_b < 0)
		{
			rrb(b);
			cheapest->cost_b++;
		}
	}
}
