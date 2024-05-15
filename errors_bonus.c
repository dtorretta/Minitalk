/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:35 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/15 15:52:35 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_msg(int i)
{
	if (i == 1)
	{
		ft_printf("%s\nError. please follow the format: <server_pid>", RED);
		ft_printf(" <text to send>\n");
		ft_printf("%s\nIf the text to send contains more than one word, ",
			END);
		ft_printf("please enclose it in quotes\n");
		ft_printf("\nexample: 1234 \"This is an example\"\n\n");
	}
	else if (i == 2)
		ft_printf("%s\nError: The PID must be a positive integer.\n\n", RED);
	else if (i == 3)
		ft_printf("%s\nError: Please, insert a non-empty message.\n\n", RED);
	else if (i == 4)
		ft_printf("\n%s client: unexpected error.\n", RED);
	ft_printf("%s", END);
	exit(EXIT_FAILURE);
}
