/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:37:31 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/17 16:39:44 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		result = (result * 10) + nptr[i] - '0'; 
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char a[] = "---+--+1234ab567";
	char b[] = "\t-+1234ab567";
	char c[] = "  +1234ab567";
	char d[] = "+12";
	
	printf("%d\n", ft_atoi(a));
	printf("%d\n", atoi(a));
	
	printf("%d\n", ft_atoi(b));
	printf("%d\n", atoi(b));
		
	printf("%d\n", ft_atoi(c));
	printf("%d\n", atoi(c));
	
	printf("%d\n", ft_atoi(d));
	printf("%d\n", atoi(d));
		
	return(0);
}*/