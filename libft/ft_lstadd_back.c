/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:21:49 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:48:17 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	temp = ft_lstlast(temp);
	temp -> next = new;
	new -> prev = temp;
}

//void	ft_lstadd_back(t_list **lst, t_list *new)
//{
//	t_list	*temp;
//
//	if (new == NULL)
//		return ;
//	if (*lst == NULL)
//	{
//		*lst = new;
//		return ;
//	}
//	temp = *lst;
//	temp = ft_lstlast(temp);
//	temp -> next = new;
//}
