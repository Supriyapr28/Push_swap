/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:39:11 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:39:11 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->rank = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value, int index)
{
	t_node	*node;

	node = create_node(value, index);
	if (!node)
		error_exit("Memory allocation failed\n");
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
