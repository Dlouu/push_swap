/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:50:04 by mbaumgar          #+#    #+#             */
/*   Updated: 2024/05/09 13:45:29 by mbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If no parameters are specified, the program must not display anything and
give the prompt back.
• In case of error, it must display "Error" followed by a ’\n’ on the
standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.*/

#include "./../inc/push_swap.h"

static int	check_sorted(int nb, char **numbers)
{
	int	i;

	i = 1;
	while (i < nb - 1)
	{
		if (ft_atoi(numbers[i]) > ft_atoi(numbers[i + 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	check_duplicate(int nb, int i, char **numbers)
{
	int	j;

	j = 1;
	while (j < nb)
	{
		i = j + 1;
		while (i < nb)
		{
			if (ft_atoi(numbers[j]) == ft_atoi(numbers[i]))
				return (FAILURE);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

static int	check_digit(char *nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (FAILURE);
	if (!ft_issign(nb[i]) && !ft_isdigit(nb[i]))
		return (FAILURE);
	if (ft_issign(nb[i]) && (nb[i + 1] == '\0'))
		return (FAILURE);
	i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	parsing(int nb, char **numbers)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		if (!check_digit(numbers[i]))
			clean_exit(FAILURE, NULL, NULL);
		if (!ft_int_ovcheck(numbers[i]))
			clean_exit(FAILURE, NULL, NULL);
		if (!check_duplicate(nb, i, numbers))
			clean_exit(FAILURE, NULL, NULL);
		i++;
	}
	if (check_sorted(nb, numbers))
		clean_exit(SUCCESS, NULL, NULL);
	return (0);
}
