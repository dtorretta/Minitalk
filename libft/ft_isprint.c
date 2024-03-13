/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:11:22 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:18 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int a = 5;
	
	if (ft_isprint(a)) 
		printf("%c is printable.\n", a);
    else 
	   	printf("%c is not printable.\n", a);
	
	if (isprint(a)) 
		printf("%c is printable.\n", a);
    else 
	   	printf("%c is not printable.\n", a);
}*/