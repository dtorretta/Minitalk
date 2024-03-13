/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:52:15 by dtorrett          #+#    #+#             */
/*   Updated: 2024/01/09 20:43:32 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_arg(va_list args, char format, int *count)
{
	unsigned long long	p;

	if (format == 's')
		ft_putstr(va_arg(args, char *), 1, count, format);
	else if (format == '%')
		ft_putchar('%', 1, count);
	else if (format == 'c')
		ft_putchar(va_arg(args, int), 1, count);
	else if (format == 'p')
	{
		p = va_arg(args, unsigned long long);
		if (p == 0)
			ft_putstr("(nil)", 1, count, format);
		else
		{
			ft_putstr("0x", 1, count, format);
			ft_puthex_fd(p, 1, count, format);
		}
	}
	else if (format == 'x' || format == 'X')
		ft_puthex_fd(va_arg(args, unsigned int), 1, count, format);
	else if (format == 'u')
		ft_putnbr(va_arg(args, unsigned int), 1, count);
	else if (format == 'd' || format == 'i')
		ft_putstr(ft_itoa(va_arg(args, int)), 1, count, format);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = 0;
	if (!str[i])
		return (-1);
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_arg(args, str[i], &count);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char			character;
// 	char			*string;
// 	int				decimalnumber;
// 	unsigned int	unsigneddecimal;
// 	void			*pointer;

// 	string = "Hello World";
// 	character = 'A';
// 	decimalnumber = 42;
// 	unsigneddecimal = -123;
// 	pointer = &decimalnumber;
// 	ft_printf("Character: %c & String: %s\n", character, string);
// 	printf("Character: %c & String: %s\n", character, string);
// 	ft_printf("Pointer in hexadecimal: %p\n", pointer);
// 	printf("Pointer in hexadecimal: %p\n", pointer);
// 	ft_printf("Decimal: %d & Integer: %i\n", decimalnumber, decimalnumber);
// 	printf("Decimal: %d & Integer: %i\n", decimalnumber, decimalnumber);
// 	ft_printf("Unsigned decimal number: %u\n", unsigneddecimal);
// 	printf("Unsigned decimal number: %u\n", unsigneddecimal);
// 	ft_printf("Number in hexadecimal (lowercase): %x\n", decimalnumber);
// 	printf("Number in hexadecimal (lowercase): %x\n", decimalnumber);
// 	ft_printf("Number in hexadecimal (uppercase): %X\n", decimalnumber);
// 	printf("Number in hexadecimal (uppercase): %X\n", decimalnumber);
// 	ft_printf("Literal percentage sign: %%\n");
// 	printf("Literal percentage sign: %%\n");
// 	return (0);
// }
