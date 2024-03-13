/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:06:29 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/01 15:56:12 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL )
		return ;
	new -> next = *lst;
	new -> prev = NULL;
	if (*lst != NULL)
		(*lst) -> prev = new;
	*lst = new;
}
