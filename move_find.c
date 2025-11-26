/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:49 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:50 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	find_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_move	cheapest;
	t_move	candidate;
	int		pos;

	cheapest.cost = INT_MAX;
	pos = 0;
	current = b->head;
	while (current)
	{
		candidate.b_pos = pos;
		candidate.target_pos = find_target_position(a, current->value);
		calculate_move_cost(&candidate, b->size, a->size);
		if (candidate.cost < cheapest.cost)
			cheapest = candidate;
		pos++;
		current = current->next;
	}
	return (cheapest);
}
