/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:01:28 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 19:36:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, (len1 + 1));
	ft_strlcat(dest, s2, (len1 + len2 + 1));
	return (dest);
}
/*
int	main(void)
{
	char const a[] = "hello ";
	char const b[] = "world";
	printf("%s\n", ft_strjoin(a, b));
	
	return (0);
}*/