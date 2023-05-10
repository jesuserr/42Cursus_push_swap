/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:21:20 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/10 11:46:17 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	list_is_sorted(t_stack *lst)
{
	t_node	*tmp;
	size_t	i;

	tmp = lst->head;
	i = lst->size - 1;
	while (i)
	{
		if (tmp->parse > tmp->next->parse)
			return (LIST_UNSORTED);
		tmp = tmp->next;
		i--;
	}
	return (LIST_SORTED);
}

void	stack_parsing(t_stack *lst)
{
	t_node	*aux_1;
	t_node	*aux_2;
	t_node	*aux_3;
	int		min_value;
	size_t	i;	

	aux_3 = lst->head;
	i = 1;
	while (lst->size - i + 1)
	{
		while (aux_3->parse != 0)
			aux_3 = aux_3->next;
		min_value = aux_3->value;
		aux_3->parse = i;
		aux_2 = aux_3;
		aux_1 = aux_3->next;
		while (aux_1)
		{
			if (aux_1->value < min_value && aux_1->parse == 0)
				aux_2 = stack_parsing_aux(aux_1, aux_2, &min_value, i);
			aux_1 = aux_1->next;
		}
		i++;
	}
}

t_node	*stack_parsing_aux(t_node *aux_1, t_node *aux_2, int *min, size_t i)
{
	*min = aux_1->value;
	aux_1->parse = i;
	aux_2->parse = 0;
	return (aux_1);
}
