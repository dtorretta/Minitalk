/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:36:09 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 20:22:49 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[a] && a < len)
	{
		if (big[a] == little[0] && (a + b) <= len)
		{
			if (ft_memcmp(big + a, little, b) == 0)
				return ((char *)big + a);
		}
		a++;
	}
	return (NULL);
}
/*
int 	main(void)
{
	const char bigger[] = "be vida es bella jajajaj";
	const char smaller[] = "bella";
	size_t len = ft_strlen(bigger);
	
	char *result = ft_strnstr(bigger, smaller, len);
	if (result != 0)
		printf("%s\n", result);
	else
		printf("null");


	char *resultb = strnstr(bigger, smaller, len);
	if (resultb != 0)
		printf("%s\n", resultb);
	else
		printf("null");

	return(0);
}*/
