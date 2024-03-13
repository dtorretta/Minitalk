/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:44:08 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 18:36:18 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/*
int	main (void)
{
	char a[] = "hello darkness my old friend";
	char b[] = "helle darkness my old friend";
	size_t n = 5;
	
	int result = ft_memcmp(a, b, n);
	if (result == 0)
		printf("Equal \n");
	else
		printf("%d\n", result);
	

	int resultb = memcmp(a, b, n);
	if (resultb == 0)
		printf("Equal \n");
	else
		printf("%d\n", resultb);
}*/
