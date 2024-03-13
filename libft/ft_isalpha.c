/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:25:39 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:35 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int	main (void)
{
	int a = 'b';
	
	if (ft_isalpha(a)) 
		printf("%c is alpha.\n", a);
    else 
	   	printf("%c is not alpha.\n", a);

	if (isalpha(a)) 
		printf("%c is alpha.\n", a);
    else 
	   	printf("%c is not alpha.\n", a);
}*/
