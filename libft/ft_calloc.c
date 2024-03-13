/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:00:16 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 18:38:20 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;

	arr = (unsigned char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
/*
int	main(void)
{
	size_t n = 5;
	size_t size = sizeof(int);
	size_t i = 0;
	int *arr1 = ft_calloc(n, size);
	int *arr2 = calloc(n, size);
	
	while (i < n)
	{
		printf("%d", arr1[i]);
		i++;
	}
	printf("\n");
	i = 0;

	while (i < n)
	{
		printf("%d", arr2[2]);
		i++;
	}
	printf("\n");
	return(0);
}*/