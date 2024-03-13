/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:51:17 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/27 16:16:01 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char)c;
	while (n && *ptr != c)
	{
		++ptr;
		--n;
	}
	if (n)
		return ((void *)ptr);
	else
		return (NULL);
}
/*
int	main(void)
{
	char a[] = "Hello world";
	int c = 'w';
	size_t size = 11;
	
	char *result = memchr(a, c, size);
	printf("direction %p\n", ft_memchr(a, c, size));
	printf("position %ld\n", result - a);
	
	char *resultb = memchr(a, c, size);
	printf("direction %p\n", memchr(a, c, size));
	printf("position %ld\n", resultb - a);
	
	return(0);
}*/