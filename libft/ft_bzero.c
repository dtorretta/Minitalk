/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:24:21 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:29 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = s;
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	a[20];
	size_t i = 0;
	
	ft_bzero(a, 10);
	while (i < sizeof(a))
    {
        printf("%hhu ", a[i]);
        i++;
    }
    printf("\n");
	
	bzero(a, 10);
	i = 0;
	while (i < sizeof(a))
    {
        printf("%hhu ", a[i]);
        i++;
    }
	return(0);
}*/