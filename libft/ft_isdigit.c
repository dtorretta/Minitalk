/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:11:22 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:13 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int a = '5';
	
	if (ft_isdigit(a)) 
		printf("%c is a digit.\n", a);
    else 
	   	printf("%c is not a digit.\n", a);
		
	if (isdigit(a)) 
		printf("%c is a digit.\n", a);
    else 
	   	printf("%c is not a digit.\n", a);

}*/