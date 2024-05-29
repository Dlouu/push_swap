/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:01 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:31 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	select_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ps_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		clean_exit(SUCCESS, a, b);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort(a, b);
}

char	*sort_index(int n, char **nbr)
{
	int		i;
	char	*swap;

	i = 1;
	while (i < n - 1)
	{
		if (ft_atoi(nbr[i]) > ft_atoi(nbr[i + 1]))
		{
			swap = nbr[i];
			nbr[i] = nbr[i + 1];
			nbr[i + 1] = swap;
			i = 0;
		}
		i++;
	}
	return (*nbr);
}

void	set_index(int n, char **nbr, t_stack **stack)
{
	t_stack	*head;
	int		i;

	head = *stack;
	i = 1;
	sort_index(n, nbr);
	while (i < n)
	{
		while ((*stack)->content != ft_atoi(nbr[i]))
			*stack = (*stack)->next;
		(*stack)->index = i++;
	}
	*stack = head;
}

t_stack	*create_stack(int n, char **numbers)
{
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	while (--n > 0)
	{
		new = ps_lstnew(ft_atoi(numbers[n]));
		ps_lstadd(&stack, new);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	parsing(argc, argv);
	a = create_stack(argc, argv);
	b = NULL;
	set_index(argc, argv, &a);
	select_sort(&a, &b);
	clean_exit(SUCCESS, &a, &b);
	return (EXIT_SUCCESS);
}
