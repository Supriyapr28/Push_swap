/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:44 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:45 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rr_moves(t_stack *a, t_stack *b, t_move move)
{
	int	i;

	i = 0;
	while (i < move.rr_count)
	{
		execute_operation(a, b, "rr");
		i++;
	}
	i = 0;
	while (i < move.rrr_count)
	{
		execute_operation(a, b, "rrr");
		i++;
	}
}

static void	execute_ra_moves(t_stack *a, t_stack *b, t_move move)
{
	int	i;

	i = 0;
	while (i < move.ra_count)
	{
		execute_operation(a, b, "ra");
		i++;
	}
	i = 0;
	while (i < move.rra_count)
	{
		execute_operation(a, b, "rra");
		i++;
	}
}

static void	execute_rb_moves(t_stack *a, t_stack *b, t_move move)
{
	int	i;

	i = 0;
	while (i < move.rb_count)
	{
		execute_operation(a, b, "rb");
		i++;
	}
	i = 0;
	while (i < move.rrb_count)
	{
		execute_operation(a, b, "rrb");
		i++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_move move)
{
	execute_rr_moves(a, b, move);
	execute_ra_moves(a, b, move);
	execute_rb_moves(a, b, move);
	execute_operation(a, b, "pa");
}
