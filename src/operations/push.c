/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:23:48 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:51 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

static void	push(t_stack **origin, t_stack **target)
{
	t_stack	*to_push;

	if (!*origin)
		return ;
	to_push = *origin;
	if (to_push == (*origin)->next)
	{
		ps_lstadd(target, to_push);
		*origin = NULL;
		return ;
	}
	*origin = (*origin)->next;
	(*origin)->prev = (*origin)->prev->prev;
	(*origin)->prev->next = *origin;
	if (!*target)
	{
		ps_lstadd(target, to_push);
		(*target)->next = *target;
		(*target)->prev = *target;
		return ;
	}
	ps_lstadd(target, to_push);
}

// pa (push a):
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

// pb (push b): 
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
