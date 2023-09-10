/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:52:23 by jesuserr          #+#    #+#             */
/*   Updated: 2023/09/10 19:54:04 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

char	*moves_reading(t_stack *lst_a, t_stack *lst_b)
{
	char	*input;
	char	*actions;

	actions = (char *)malloc (sizeof(char));
	*actions = 0;
	if (!actions)
	{
		ft_total_free(lst_a, lst_b);
		ft_error_handler(ERROR_MALLOC);
	}
	input = get_next_line(1);
	while (input != NULL)
	{
		actions = assign_actions(input, actions);
		if (!actions)
		{
			ft_total_free(lst_a, lst_b);
			free(input);
			ft_error_handler(ERROR);
		}
		free (input);
		input = get_next_line(1);
	}
	return (actions);
}

char	*assign_actions(char *input, char *actions)
{
	if (!ft_strncmp(input, "sa", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "0", 1));
	else if (!ft_strncmp(input, "sb", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "1", 1));
	else if (!ft_strncmp(input, "ss", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "2", 1));
	else if (!ft_strncmp(input, "ra", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "3", 1));
	else if (!ft_strncmp(input, "rb", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "4", 1));
	else if (!ft_strncmp(input, "rr", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "5", 1));
	else if (!ft_strncmp(input, "rra", 3) && gnl_strlen(input) == 4)
		return (gnl_strjoin(actions, "6", 1));
	else if (!ft_strncmp(input, "rrb", 3) && gnl_strlen(input) == 4)
		return (gnl_strjoin(actions, "7", 1));
	else if (!ft_strncmp(input, "rrr", 3) && gnl_strlen(input) == 4)
		return (gnl_strjoin(actions, "8", 1));
	else if (!ft_strncmp(input, "pa", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "9", 1));
	else if (!ft_strncmp(input, "pb", 2) && gnl_strlen(input) == 3)
		return (gnl_strjoin(actions, "A", 1));
	else
		free(actions);
	return (0);
}

void	apply_moves(t_stack *lst_a, t_stack *lst_b, char *moves)
{
	while (*moves)
	{
		apply_moves_aux(lst_a, lst_b, *moves);
		moves++;
	}
}

void	apply_moves_aux(t_stack *lst_a, t_stack *lst_b, char moves)
{
	if (moves == '0')
		swap(lst_a);
	else if (moves == '1')
		swap(lst_b);
	else if (moves == '2')
		swap_both(lst_a, lst_b);
	else if (moves == '3')
		rotate(lst_a);
	else if (moves == '4')
		rotate(lst_b);
	else if (moves == '5')
		rotate_both(lst_a, lst_b);
	else if (moves == '6')
		reverse_rotate(lst_a);
	else if (moves == '7')
		reverse_rotate(lst_b);
	else if (moves == '8')
		reverse_rotate_both(lst_a, lst_b);
	else if (moves == '9')
		push(lst_b, lst_a);
	else if (moves == 'A')
		push(lst_a, lst_b);
}

void	print_results(t_stack *lst_a, t_stack *lst_b)
{
	if (list_is_sorted(lst_a) && lst_b->size == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
