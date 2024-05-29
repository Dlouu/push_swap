/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:42 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:47 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	ps_lstadd(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
		new->prev->next = new;
		*lst = new;
	}
}

t_stack	*ps_lstnew(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = -1;
	new->content = number;
	new->direction = 0;
	new->position = -1;
	new->cost = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->best = -1;
	new->target = new;
	new->prev = new;
	new->next = new;
	return (new);
}

int	ps_lstsize(t_stack *lst)
{
	t_stack	*end;
	int		size;

	size = 0;
	if (!lst)
		return (0);
	end = lst;
	while (1)
	{
		lst = lst->next;
		size++;
		if (lst == end)
			break ;
	}
	return (size);
}

void	ps_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;
	t_stack	*end;

	if (!lst || !del)
		return ;
	end = *lst;
	while (1)
	{
		temp = *lst;
		*lst = (*lst)->next;
		(*del)(temp);
		if (*lst == end)
			break ;
	}
	*lst = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (SUCCESS);
	while (1)
	{
		if (temp->content > temp->next->content)
			return (FAILURE);
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (SUCCESS);
}
