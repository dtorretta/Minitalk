/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:25:52 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 18:09:39 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	size;

	size = ft_strlen (s);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
char	ft_test(unsigned int i, char c)
{
	i = 0;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	main(void)
{
	char	str[] = "Hello";
	char *result = ft_strmapi(str, ft_test);
	printf("%s\n", result);
	free(result);
	return(0);	
}*/