/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:21:22 by dtorrett          #+#    #+#             */
/*   Updated: 2023/12/14 20:38:03 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	if (!s || !*s)
		return (NULL);
	len = ft_strlen(s);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len--)
		dest[len] = s[len];
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin_2(char *s1, const char *s2)
{
	char	*r;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!r)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	r[len1 + len2] = '\0';
	while (len2--)
		r[len1 + len2] = s2[len2];
	while (len1--)
		r[len1] = s1[len1];
	if (s1)
		free(s1);
	return (r);
}
