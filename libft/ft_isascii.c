/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:11:22 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:09 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int a = 128;
	
	if (ft_isascii(a)) 
		printf("%c is ascii.\n", a);
    else 
	   	printf("%c is not ascii.\n", a);

	if (isascii(a)) 
		printf("%c is ascii.\n", a);
    else 
	   	printf("%c is not ascii.\n", a);
}*/