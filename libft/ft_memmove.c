/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:30:42 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:54:11 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	else 
	{
		d = (char *)dest;
		s = (const char *)src;
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
int	main(void) 
{
    char src[] = "Hello world";
    char dest[20];
	
	ft_memmove(dest, src, 11);
    printf("%s\n", dest);

	memmove(dest, src, 11);
    printf("%s\n", dest);

	return(0);
}*/
