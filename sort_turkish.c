/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:39:07 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:39:08 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk_size(int n)
{
	if (n <= 100)
		return (n / 5);
	else if (n <= 250)
		return (n / 6);
	else
		return (n / 8);
}

static void	push_element_to_b(t_stack *a, t_stack *b, int cm, int cs, int *p)
{
	if (a->head->value <= cm)
	{
		execute_operation(a, b, "pb");
		(*p)++;
		if (b->size > 1 && b->head->value < cm - cs / 2)
			execute_operation(a, b, "rb");
	}
	else
		execute_operation(a, b, "ra");
}

static void	push_phase(t_stack *a, t_stack *b, int chunksize)
{
	int	pushed;
	int	current_max;

	pushed = 0;
	current_max = chunksize - 1;
	while (a->size > 3)
	{
		push_element_to_b(a, b, current_max, chunksize, &pushed);
		if (pushed == current_max + 1)
			current_max += chunksize;
	}
}

static void	final_rotation(t_stack *a, t_stack *b)
{
	int	min;
	int	min_pos;

	min = find_min(a);
	min_pos = get_position(a, min);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			execute_operation(a, b, "ra");
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			execute_operation(a, b, "rra");
	}
}

void	turkish_sort(t_stack *a, t_stack *b)
{
	int		chunksize;
	t_move	move;

	if (a->size <= 3)
	{
		sort_three(a, b);
		return ;
	}
	chunksize = calculate_chunk_size(a->size);
	push_phase(a, b, chunksize);
	sort_three(a, b);
	while (b->size > 0)
	{
		move = find_cheapest_move(a, b);
		execute_move(a, b, move);
	}
	final_rotation(a, b);
}
