/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:21:01 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/10 13:17:44 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_program(int argc, char **argv)
{
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*moves;

	stack_a = ft_new_stack(0);
	stack_b = ft_new_stack(stack_a);
	while (argc-- > 1)
	{
		node = ft_new_node(ft_atoi(argv[argc]));
		if (!node)
		{
			ft_total_free(stack_a, stack_b);
			ft_error_handler(ERROR_MALLOC_NODE);
		}
		ft_add_node_front(stack_a, node);
	}
	stack_parsing(stack_a);
	moves = moves_reading(stack_a, stack_b);
	apply_moves(stack_a, stack_b, moves);
	print_results(stack_a, stack_b);
	free(moves);
	ft_total_free(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		detect_no_numbers(argc, argv);
		detect_duplicates_and_limits(argc, argv);
		init_program(argc, argv);
	}	
	return (0);
}
