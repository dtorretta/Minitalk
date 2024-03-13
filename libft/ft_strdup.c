/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:30:11 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:56:56 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)); 
	if (dest == NULL)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main (void)
{
	const char *org = "Hello world";
	char *res = ft_strdup(org);
	
	printf("%s\n", res);
	printf("%s\n", strdup(org));
	
	return (0);
}*/