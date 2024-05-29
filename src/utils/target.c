/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:45:35 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 17:13:36 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	update_position(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	int		median;

	i = 0;
	if (!*stack)
		return ;
	temp = *stack;
	median = ps_lstsize(*stack) / 2;
	while (1)
	{
		temp->position = i;
		if (i <= median)
			temp->direction = UP;
		else
			temp->direction = DOWN;
		i++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}

t_stack	*select_cheapest_target(t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*b_end;

	cheapest = b;
	b_end = b;
	while (1)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
		if (b == b_end)
			break ;
	}
	return (cheapest);
}

void	set_cost(t_stack *a, t_stack *b)
{
	t_stack	*b_end;
	int		size_a;
	int		size_b;

	size_a = ps_lstsize(a);
	size_b = ps_lstsize(b);
	b_end = b;
	update_position(&a);
	update_position(&b);
	while (1)
	{
		b->cost_b = b->position;
		if (b->position > size_b / 2)
			b->cost_b = (size_b - b->position) * -1;
		b->cost_a = b->target->position;
		if (b->target->position > size_a / 2)
			b->cost_a = (size_a - b->target->position) * -1;
		b->cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
		b = b->next;
		if (b == b_end)
			break ;
	}
}

void	set_best_target(int best, t_stack *best_target, t_stack *b, t_stack *a)
{
	if (best != INT_MAX)
		b->target = best_target;
	else
		b->target = find_min(a);
}

void	set_target(t_stack *a, t_stack *b, int best)
{
	t_stack		*b_end;
	t_stack		*a_end;
	t_stack		*best_target;

	b_end = b;
	a_end = a;
	while (1)
	{
		best = INT_MAX;
		while (1)
		{
			if (a->index > b->index && a->index < best)
			{
				best_target = a;
				best = a->index;
			}
			a = a->next;
			if (a == a_end)
				break ;
		}
		set_best_target(best, best_target, b, a);
		b = b->next;
		if (b == b_end)
			break ;
	}
}
