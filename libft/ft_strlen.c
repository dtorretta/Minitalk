/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:07:29 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:57:52 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
/*
int	main(void)
{
	char a[] = "be vida es bella";
	
	printf("%zu\n", ft_strlen(a));
	printf("%zu\n", strlen(a));
	
	return (0); 
}*/
