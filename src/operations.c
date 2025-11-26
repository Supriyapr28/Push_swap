/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:56 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:57 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*old_head;

	if (!stack->head || !stack->head->next)
		return ;
	old_head = stack->head;
	stack->head = old_head->next;
	stack->head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = stack->tail;
	stack->tail->next = old_head;
	stack->tail = old_head;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*old_tail;

	if (!stack->head || !stack->head->next)
		return ;
	old_tail = stack->tail;
	stack->tail = old_tail->prev;
	stack->tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = stack->head;
	stack->head->prev = old_tail;
	stack->head = old_tail;
}
