/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:48:47 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:49 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack)
		return ;
	last = (*stack)->prev;
	first = (*stack);
	second = (*stack)->next;
	third = (*stack)->next->next;
	if (third == first)
	{
		*stack = second;
		return ;
	}
	last->next = second;
	first->next = third;
	second->next = first;
	first->prev = second;
	second->prev = last;
	third->prev = first;
	*stack = second;
}

// sa (swap a):
// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

// sb (swap b):
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

// ss (swap both):
// sa and sb at the same time. 
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
