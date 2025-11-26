/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:39:15 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:39:16 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack *stack, t_node *current)
{
	t_node	*compare;
	int		rank;

	while (current)
	{
		rank = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

static void	update_values(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->value = current->rank;
		current = current->next;
	}
}

void	normalize_values(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	assign_ranks(stack, current);
	update_values(stack);
}
