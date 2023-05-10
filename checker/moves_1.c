/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:21:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/10 10:50:34 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *lst)
{
	int		temp;
	size_t	temp2;

	if (lst->size > 1)
	{
		temp = lst->head->value;
		temp2 = lst->head->parse;
		lst->head->value = lst->head->next->value;
		lst->head->parse = lst->head->next->parse;
		lst->head->next->value = temp;
		lst->head->next->parse = temp2;
	}
}

void	swap_both(t_stack *lst_a, t_stack *lst_b)
{
	if (lst_a->size > 1 && lst_b->size > 1)
	{
		swap(lst_a);
		swap(lst_b);
	}
}

void	push(t_stack *lst_a, t_stack *lst_b)
{
	t_node	*temp;

	if (lst_a->size == 0)
		return ;
	temp = lst_a->head->next;
	ft_add_node_front(lst_b, lst_a->head);
	lst_a->size--;
	if (lst_a->size == 0)
		lst_a->tail = NULL;
	lst_a->head = temp;
}

void	rotate(t_stack *lst)
{
	t_node	*temp;

	if (lst->size > 1)
	{
		temp = lst->head;
		lst->head = lst->head->next;
		lst->tail->next = temp;
		lst->tail = temp;
		lst->tail->next = NULL;
	}
}

void	rotate_both(t_stack *lst_a, t_stack *lst_b)
{
	if (lst_a->size > 1 && lst_b->size > 1)
	{
		rotate(lst_a);
		rotate(lst_b);
	}
}
