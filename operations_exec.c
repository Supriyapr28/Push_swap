/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:52 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:54 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_swap(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a' && !op[2])
		swap_stack(a);
	else if (op[1] == 'b' && !op[2])
		swap_stack(b);
	else if (op[1] == 's' && !op[2])
	{
		swap_stack(a);
		swap_stack(b);
	}
}

static void	exec_push(t_stack *a, t_stack *b, char *op)
{
	t_node	*node;

	if (op[1] == 'a' && !op[2])
	{
		node = pop(b);
		if (node)
		{
			push(a, node->value, node->index);
			free(node);
		}
	}
	else if (op[1] == 'b' && !op[2])
	{
		node = pop(a);
		if (node)
		{
			push(b, node->value, node->index);
			free(node);
		}
	}
}

static void	exec_rotate(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a' && !op[2])
		rotate_stack(a);
	else if (op[1] == 'b' && !op[2])
		rotate_stack(b);
	else if (op[1] == 'r' && !op[2])
	{
		rotate_stack(a);
		rotate_stack(b);
	}
}

static void	exec_reverse_rotate(t_stack *a, t_stack *b, char *op)
{
	if (op[2] == 'a' && !op[3])
		reverse_rotate_stack(a);
	else if (op[2] == 'b' && !op[3])
		reverse_rotate_stack(b);
	else if (op[2] == 'r' && !op[3])
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
}

void	execute_operation(t_stack *a, t_stack *b, char *op)
{
	if (!op)
		return ;
	if (op[0] == 's')
		exec_swap(a, b, op);
	else if (op[0] == 'p')
		exec_push(a, b, op);
	else if (op[0] == 'r' && op[1] == 'r' && op[2])
		exec_reverse_rotate(a, b, op);
	else if (op[0] == 'r')
		exec_rotate(a, b, op);
	ft_putstr(op);
	ft_putstr("\n");
}
