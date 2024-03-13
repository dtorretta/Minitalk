/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:52:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/09 20:15:51 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd, int *count)
{
	if (write(fd, &c, 1))
		(*count)++;
}

void	ft_putstr(char *s, int fd, int *count, char conv)
{
	if (!s)
	{
		(*count) += 6;
		write(fd, "(null)", 6);
	}
	else 
	{
		write(fd, s, ft_strlen(s));
		(*count) += ft_strlen(s);
	}
	if (conv == 'i' || conv == 'd')
		free(s);
}

void	ft_putnbr(unsigned int n, int fd, int *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, fd, count);
		ft_putnbr(n % 10, fd, count);
	}
	else
		ft_putchar('0' + n, fd, count);
}

void	ft_puthex_fd(unsigned long long n, int fd, int *count, char conv)
{
	if (n < 10)
		ft_putchar(n + '0', fd, count);
	else if ((n < 16) && ((conv == 'x') || (conv == 'p')))
		ft_putchar('a' + (n - 10), fd, count);
	else if ((n < 16) && ((conv == 'X')))
		ft_putchar('A' + (n - 10), fd, count);
	else
	{
		ft_puthex_fd(n / 16, fd, count, conv);
		ft_puthex_fd(n % 16, fd, count, conv);
	}
}
