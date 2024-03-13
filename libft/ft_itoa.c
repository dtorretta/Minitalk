/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:13:32 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 19:57:02 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fullspaces(char *res, int n, int size, int i)
{
	while (size > i)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

static	int	ft_size(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0) 
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = ft_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
		n = -n;
	}
	ft_fullspaces(res, n, size, i);
	res[size] = '\0';
	return (res);
}
/*
int	main(void)
{
	int	a = 0;
	int	b = -42;
	int	c = -2147483648;
	int	d = 2147483647;
	
	printf("%s\n", ft_itoa(a));
	printf("%s\n", ft_itoa(b));
	printf("%s\n", ft_itoa(c));
	printf("%s\n", ft_itoa(d));
	return(0);
}*/