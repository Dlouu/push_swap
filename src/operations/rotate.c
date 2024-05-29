/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:14:17 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:51 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

static void	rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

// ra (rotate a): 
// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

// rb (rotate b): 
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

// rr (rotate both): 
// ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
