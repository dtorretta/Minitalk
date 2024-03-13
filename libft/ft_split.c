/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:50:36 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/15 17:59:40 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_allocate(char **tab, char const *s, char sep)
{
	size_t	i;
	size_t	element;
	size_t	start;

	i = 0;
	start = 0;
	element = 0;
	while (s[i])
	{
		while (s[i] == sep)
		{
			i++;
			start++;
		}
		while (s[i] != sep && s[i])
			i++;
		if (i > start)
		{
			tab[element] = ft_substr(s, start, (i - start));
			element++;
		}
		start = i;
	}
	tab[element] = NULL;
}

static int	count_words(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char sep)
{
	char	**array; 
	size_t	size;

	if (!s)
		return (NULL);
	size = count_words(s, sep);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	ft_allocate(array, s, sep);
	return (array);
}
/*
int	main(void)
{
	char const a[] = "lord of the lost";
	char sep = ' ';
	size_t i = 0;

	char **arr = ft_split (a, sep);
	
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	free(arr); 
	return(0);
}*/