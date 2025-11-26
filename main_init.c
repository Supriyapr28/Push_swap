/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaipur- <spaipur-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:38:05 by spaipur-          #+#    #+#             */
/*   Updated: 2025/11/26 10:38:17 by spaipur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_arguments(t_stack *a, int argc, char **argv)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(a);
			error_exit("Invalid input\n");
		}
		value = ft_atoi(argv[i]);
		push(a, value, argc - 1 - i);
		i--;
	}
}

static void	init_stacks(t_stack **a, t_stack **b)
{
	*a = create_stack();
	*b = create_stack();
	if (!(*a) || !(*b))
		error_exit("Memory allocation failed\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b);
	parse_arguments(a, argc, argv);
	if (has_duplicates(a))
	{
		free_stack(a);
		free_stack(b);
		error_exit("Duplicate numbers\n");
	}
	normalize_values(a);
	if (!is_sorted(a, b))
		turkish_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
