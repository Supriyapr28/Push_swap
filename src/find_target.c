/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:37:13 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:37:49 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_best_target(t_stack *a, int value, int *mindiff)
{
	t_node	*current;
	int		pos;
	int		target;
	int		diff;

	pos = 0;
	target = -1;
	current = a->head;
	while (current)
	{
		if (current->value > value)
		{
			diff = current->value - value;
			if (diff < *mindiff)
			{
				*mindiff = diff;
				target = pos;
			}
		}
		pos++;
		current = current->next;
	}
	return (target);
}

int	find_target_position(t_stack *a, int value)
{
	int	target;
	int	mindiff;
	int	min;

	mindiff = INT_MAX;
	target = find_best_target(a, value, &mindiff);
	if (target == -1)
	{
		min = find_min(a);
		target = get_position(a, min);
	}
	return (target);
}
