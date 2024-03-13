/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:38:34 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 19:25:04 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	find;
	char	*src;

	i = ft_strlen(s);
	src = (char *)s;
	find = (char)c;
	while (i > 0)
	{
		if (src[i] == find)
			return (src + i);
		else
			i--;
	}
	if (src[i] == find)
		return (src);
	return (0);
}
/*
int 	main(void)
{
	char a[] = "la vida es bella";
	char b = 'l';
	
	char *result = ft_strrchr(a, b);
	if (result != 0)
		printf("%s\n", result);
	else
		printf("null");

	char *resultb = strrchr(a, b);
	if (resultb != 0)
		printf("%s\n", resultb);
	else
		printf("null");
		
}*/