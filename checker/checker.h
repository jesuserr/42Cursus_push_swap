/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:44 by jesuserr          #+#    #+#             */
/*   Updated: 2023/05/10 11:35:38 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              DEFINES
*/
# define BLUE       "\033[0;94m"
# define RED        "\033[0;31m"
# define WHITE      "\033[0;37m"
# define GREEN      "\033[0;92m"

# define ERROR					0
# define ERROR_MALLOC_STACK_A	2
# define ERROR_MALLOC_STACK_B	3
# define ERROR_MALLOC_NODE		4
# define ERROR_MALLOC			5
# define LIST_UNSORTED			0
# define LIST_SORTED			1

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <unistd.h>    // for write
# include <stdlib.h>    // for exit, malloc
# include <stdio.h>		// for printf QUITAR
# include <limits.h>	// for INT_MAX && INT_MIN
# include <stddef.h>	// for NULL

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	size_t			parse;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
	char	name;
}			t_stack;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/

void	init_program(int argc, char **argv);

char	*moves_reading(t_stack *lst_a, t_stack *lst_b);
char	*assign_actions(char *input, char *actions);
void	apply_moves(t_stack *lst_a, t_stack *lst_b, char *moves);
void	apply_moves_aux(t_stack *lst_a, t_stack *lst_b, char moves);
void	print_results(t_stack *lst_a, t_stack *lst_b);

void	ft_error_handler(int error);
void	detect_no_numbers(int argc, char **argv);
void	detect_duplicates_and_limits(int argc, char **argv);

t_stack	*ft_new_stack(t_stack *lst);
t_node	*ft_new_node(int number);
void	ft_add_node_front(t_stack *lst, t_node *new);
void	print_list(t_node *head);

void	swap(t_stack *lst);
void	swap_both(t_stack *lst_a, t_stack *lst_b);
void	push(t_stack *lst_a, t_stack *lst_b);
void	rotate(t_stack *lst);
void	rotate_both(t_stack *lst_a, t_stack *lst_b);

void	reverse_rotate(t_stack *lst);
void	reverse_rotate_both(t_stack *lst_a, t_stack *lst_b);

int		list_is_sorted(t_stack *lst);
void	stack_parsing(t_stack *lst);
t_node	*stack_parsing_aux(t_node *aux_1, t_node *aux_2, int *min, size_t i);

long	ft_atoi(const char *str);
int		ft_isdigit(char c);
void	ft_total_free(t_stack *lst_a, t_stack *lst_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif