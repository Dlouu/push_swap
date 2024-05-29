/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:52:33 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 14:52:03 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	clean_exit(int success, t_stack **a, t_stack **b)
{
	if (a && *a)
		ps_lstclear(a, free);
	if (b && *b)
		ps_lstclear(b, free);
	if (!success)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*temp;

	min = stack;
	temp = stack;
	while (1)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*temp;

	max = stack;
	temp = stack;
	while (1)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (max);
}

t_range	set_range(int i, int size, int blocks)
{
	t_range	range;

	range.min = i * (size / blocks);
	range.max = (i + 1) * (size / blocks);
	return (range);
}

int	set_blocks(int size)
{
	int	blocks;

	if (size < 99)
		blocks = 1;
	else if (size < 499)
		blocks = 2;
	else
		blocks = 5;
	return (blocks);
}
