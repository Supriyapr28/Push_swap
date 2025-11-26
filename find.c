/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:05 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:06 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->head)
		return (INT_MAX);
	min = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack->head)
		return (INT_MIN);
	max = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}
