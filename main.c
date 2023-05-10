/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:42:51 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/07 13:39:31 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_program(int argc, char **argv)
{
	t_node	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	sort_stack(stack_a, stack_b);
	ft_total_free(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		detect_no_numbers(argc, argv);
		detect_duplicates_limits_and_order(argc, argv);
		init_program(argc, argv);
	}	
	return (0);
}
//valgrind --leak-check=full -s ./push_swap 2 1 3 6 5 8
//printf ("\nStack A %ld\t%p\t%p", stack_a->size, stack_a->head, stack_a->tail);
//printf ("\nStack B %ld\t%p\t%p", stack_b->size, stack_b->head, stack_b->tail);
//print_list(stack_a->head);
//print_list(stack_b->head);
//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
