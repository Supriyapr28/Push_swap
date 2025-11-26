/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:52:13 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:53:36 by spaipur-         ###   ########.fr       */
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

static int	find_best(t_move *m, t_cost_params *p)
{
	int	best;
	int	c2;
	int	c3;
	int	c4;

	m->cost = max_int(p->ra, p->rb);
	best = 1;
	c2 = max_int(p->rra, p->rrb);
	c3 = p->ra + p->rrb;
	c4 = p->rra + p->rb;
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

static void	assign_rr_counts(t_move *m, t_cost_params *p)
{
	m->rr_count = min_int(p->ra, p->rb);
	m->ra_count = p->ra - m->rr_count;
	m->rb_count = p->rb - m->rr_count;
}

static void	assign_counts(t_move *m, int best, t_cost_params *p)
{
	if (best == 1)
		assign_rr_counts(m, p);
	else if (best == 2)
	{
		m->rrr_count = min_int(p->rra, p->rrb);
		m->rra_count = p->rra - m->rrr_count;
		m->rrb_count = p->rrb - m->rrr_count;
	}
	else if (best == 3)
	{
		m->ra_count = p->ra;
		m->rrb_count = p->rrb;
	}
	else
	{
		m->rra_count = p->rra;
		m->rb_count = p->rb;
	}
}

void	calculate_move_cost(t_move *move, int size_b, int size_a)
{
	t_cost_params	p;
	int				best;

	p.ra = move->target_pos;
	p.rra = size_a - move->target_pos;
	p.rb = move->b_pos;
	p.rrb = size_b - move->b_pos;
	init_counts(move);
	best = find_best(move, &p);
	assign_counts(move, best, &p);
}
