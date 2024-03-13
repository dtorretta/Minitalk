/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:52:36 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:44:48 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int a = '9';
	
	if (ft_isalnum(a)) 
		printf("%c is alphanumeric.\n", a);
    else 
	   	printf("%c is not alphanumeric.\n", a);

	if (isalnum(a)) 
		printf("%c is alphanumeric.\n", a);
    else 
	   	printf("%c is not alphanumeric.\n", a);
}*/