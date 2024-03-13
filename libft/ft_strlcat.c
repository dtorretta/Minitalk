/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:29:43 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:57:33 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	j = 0;
	lensrc = ft_strlen(src); 
	while (dst[i])
		i++;
	lendst = i;
	if (size == 0 || size <= lendst)
		return (lensrc + size);
	while (src[j] && j < size - lendst - 1) 
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (lendst + lensrc);
}
/*
int	main(void)
{
	char src[] = "hello ";
	char dst[] = "world";
	size_t size = 20;
	
	size_t result = ft_strlcat(dst, src, size);
	printf("%zu\n", result);
	printf("%s\n", dst);	
	
	return (0);
}*/
