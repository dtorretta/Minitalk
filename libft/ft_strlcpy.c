/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:14:22 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 18:47:47 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size < 1)
		return (ft_strlen(src));
	i = 0;
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
int	main(void)
{
	const char src[] = "lord";
	char dst[20];
	size_t size = 3;
		
	printf("dst: %s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, size));
	
	return (0);
}*/
