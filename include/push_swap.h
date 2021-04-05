/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:53:29 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/03 17:17:24 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../include/all.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(int val);
int					pop_pile(t_list **list);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				create_list(t_list **list, char **av);
void				affiche_list(t_list *list);
void				algo_for_three(t_list **l, t_list **lb);
void				algo_for_five(t_list **lista, t_list **listb);
int					search_next_min(t_list *list, int index);
int					is_min (int nb, t_list *list);
int					is_max(int nb, t_list *list);
int					search_min(t_list *list);
int					reverse_sort(t_list **list);
int					ft_lstsize(t_list *lst);
int					check_sort_stack(t_list **lista);
void				algo_for_hundred(t_list **a, t_list **b, int size, int val);
int					*copy_in_tab(t_list *a);
int					find_element_bloc_in_queue(t_list *a, int nb, int *bloc);
int					find_element_bloc_in_head(t_list *a, int nb, int *bloc);
void				sort_b_for_end(t_list **a, t_list **b);
int					max_in_head(t_list *b, int size, int *max);
int					max_in_queue(t_list *b, int size, int *max);
int					check_sort(t_list *lista, t_list *listb);
int					check_min_and_max(char *s);
int					check_int_type(char *s);
#endif
