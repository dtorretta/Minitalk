/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:21:25 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/27 16:21:14 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
int 	main(void)
{
	char a[] = "la vida es bella jajajaj";
	char b = 'b';
	
	char *result = ft_strchr(a, b);
	if (result != 0)
		printf("%s\n", result);
	else
		printf("null");

	char *resultb = strchr(a, b);
	if (resultb != 0)
		printf("%s\n", resultb);
	else
		printf("null");
		
}*/