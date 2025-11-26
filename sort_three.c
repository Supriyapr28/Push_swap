/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:39:04 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:39:05 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_helper(t_stack *a, t_stack *b, int first, int second)
{
	int	third;

	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		execute_operation(a, b, "sa");
	else if (first > second && second > third)
	{
		execute_operation(a, b, "sa");
		execute_operation(a, b, "rra");
	}
	else if (first > second && second < third && first > third)
		execute_operation(a, b, "ra");
	else if (first < second && second > third && first < third)
	{
		execute_operation(a, b, "sa");
		execute_operation(a, b, "ra");
	}
	else if (first < second && second > third && first > third)
		execute_operation(a, b, "rra");
}

void	sort_three(t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->head->value > a->head->next->value)
			execute_operation(a, b, "sa");
		return ;
	}
	first = a->head->value;
	second = a->head->next->value;
	sort_three_helper(a, b, first, second);
}
