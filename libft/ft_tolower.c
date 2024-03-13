/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:34:56 by dtorrett          #+#    #+#             */
/*   Updated: 2023/11/23 18:08:42 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	int a = 'M';
	
	printf("%d\n", ft_tolower(a));

	printf("%d\n", tolower(a));	
}*/