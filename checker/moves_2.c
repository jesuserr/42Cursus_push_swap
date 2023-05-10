/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:21:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/09 12:04:38 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack *lst)
{
	t_node	*temp1;
	t_node	*temp2;
	size_t	i;

	if (lst->size > 1)
	{
		temp1 = lst->head;
		temp2 = lst->head;
		i = 0;
		while (i < (lst->size - 2))
		{
			temp1 = temp1->next;
			i++;
		}
		lst->head = lst->tail;
		lst->head->next = temp2;
		lst->tail = temp1;
		lst->tail->next = NULL;
	}
}

void	reverse_rotate_both(t_stack *lst_a, t_stack *lst_b)
{
	if (lst_a->size > 1 && lst_b->size > 1)
	{
		reverse_rotate(lst_a);
		reverse_rotate(lst_b);
	}
}
