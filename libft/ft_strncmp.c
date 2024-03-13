/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:44:24 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 19:29:29 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && (ptr1[i] || ptr2[i]) && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
/*
int	main (void)
{
	char a[] = "hola mundo";
	char b[] = "hols lala";
	size_t n = 4;
	
	int result = ft_strncmp(a, b, n);
	if (result == 0)
		printf("equal \n");
	else
		printf("%d\n", result);

	int resultb = strncmp(a, b, n);
	if (resultb == 0)
		printf("equal \n");
	else
		printf("%d\n", resultb);
	
}*/