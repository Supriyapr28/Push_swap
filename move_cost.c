/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:05 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:38 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_counts(t_move *move)
{
	move->ra_count = 0;
	move->rra_count = 0;
	move->rb_count = 0;
	move->rrb_count = 0;
	move->rr_count = 0;
	move->rrr_count = 0;
}

static int	find_best(t_move *m, int c1, int c2, int c3, int c4)
{
	int	best;

	m->cost = c1;
	best = 1;
	if (c2 < m->cost)
	{
		m->cost = c2;
		best = 2;
	}
	if (c3 < m->cost)
	{
		m->cost = c3;
		best = 3;
	}
	if (c4 < m->cost)
	{
		m->cost = c4;
		best = 4;
	}
	return (best);
}

static void	assign_counts(t_move *m, int best, int ra, int rra, int rb, int rrb)
{
	if (best == 1)
	{
		m->rr_count = min_int(ra, rb);
		m->ra_count = ra - m->rr_count;
		m->rb_count = rb - m->rr_count;
	}
	else if (best == 2)
	{
		m->rrr_count = min_int(rra, rrb);
		m->rra_count = rra - m->rrr_count;
		m->rrb_count = rrb - m->rrr_count;
	}
	else if (best == 3)
	{
		m->ra_count = ra;
		m->rrb_count = rrb;
	}
	else
	{
		m->rra_count = rra;
		m->rb_count = rb;
	}
}

void	calculate_move_cost(t_move *move, int size_b, int size_a)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	best;

	ra = move->target_pos;
	rra = size_a - move->target_pos;
	rb = move->b_pos;
	rrb = size_b - move->b_pos;
	init_counts(move);
	best = find_best(move, max_int(ra, rb), max_int(rra, rrb),
			ra + rrb, rra + rb);
	assign_counts(move, best, ra, rra, rb, rrb);
}
