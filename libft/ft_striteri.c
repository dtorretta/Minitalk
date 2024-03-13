/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:02:28 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 17:57:08 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_test(unsigned int i, char *c)
{
	i = 0;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char	str[] = "Hello";
	ft_striteri(str, ft_test);
	printf("%s\n", str);
	return(0);	
}*/