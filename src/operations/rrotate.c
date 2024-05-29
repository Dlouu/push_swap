/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:47 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:50 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}

// rra (reverse rotate a): 
// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

// rrb (reverse rotate b): 
// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

// rrr (reverse rotate both): 
// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
