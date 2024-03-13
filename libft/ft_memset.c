/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:39:31 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:54:21 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int letra, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)ptr;
	while (i < n)
	{
		result[i] = letra;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	char	a[20];
	ft_memset(a, 'A', 10);
	printf("%s\n", a);
	memset(a, 'B', 10);
	printf("%.*s", 10, a);

	return(0);
}*/