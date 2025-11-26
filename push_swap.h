/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:39:00 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:39:01 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_move
{
	int	b_pos;
	int	target_pos;
	int	cost;
	int	ra_count;
	int	rb_count;
	int	rra_count;
	int	rrb_count;
	int	rr_count;
	int	rrr_count;
}	t_move;

/* main.c */
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	error_exit(const char *msg);
int		ft_atoi(const char *str);

/* stack.c */
t_node	*create_node(int value, int index);
t_stack	*create_stack(void);
void	push(t_stack *stack, int value, int index);
t_node	*pop(t_stack *stack);
void	free_stack(t_stack *stack);

/* operations.c */
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	execute_operation(t_stack *a, t_stack *b, char *op);

/* utils.c */
void	ft_putstr(char *str);
void	normalize_values(t_stack *stack);
int		is_sorted(t_stack *a, t_stack *b);
int		min_int(int a, int b);
int		max_int(int a, int b);

/* find.c */
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		find_target_position(t_stack *a, int value);

/* move.c */
void	calculate_move_cost(t_move *move, int sizeb, int sizea);
t_move	find_cheapest_move(t_stack *a, t_stack *b);
void	execute_move(t_stack *a, t_stack *b, t_move move);

/* sort.c */
void	sort_three(t_stack *a, t_stack *b);
void	turkish_sort(t_stack *a, t_stack *b);

#endif
