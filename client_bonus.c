/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:44 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/15 15:52:44 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

//Each char has its binary representation composed of 8 bits combining 0 and 1
//it checks if the most significant bit (leftmost) is 1 (& 128). 
//If it's 1, it sends SIGUSR1 signal. If it's 0, it sends SIGUSR2 signal.
//(c = c << 1) moves to the next bit of the character.
static void	char_to_bin(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg(4);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg(4);
		}
		c = c << 1;
		bit++;
		pause();
		usleep(100);
	}
}

//It iterates char by char and calls the fx chartobin.
//At the end, it sends the null character to indicate the end of the text.
static void	text_sender(char *text, int s_pid)
{
	int	i;

	i = 0;
	while (text[i])
	{
		char_to_bin(text[i], s_pid);
		i++;
	}
	char_to_bin('\0', s_pid);
}

//When SIGUSR2 is received, it just increases a received signals counter. 
//Until SIGUSR1 is received, it means that not all the text has been sent.
//When SIGUSR1 is received, the signals were successfully sent.
static void	signal_handler(int sig)
{
	static int	signal = 0;

	if (sig == SIGUSR1)
	{
		ft_printf("\n%s%d Signals sent successfully!\n", GREEN, ++signal);
		ft_printf("%s", END);
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGUSR2)
		signal++;
}

//Error managing: cero/negativ PID or non numeric arguments
int	main(int argc, char **argv)
{
	pid_t	pid_client;
	pid_t	pid_server;

	if (argc != 3)
		error_msg(1);
	pid_client = getpid();
	pid_server = atoi(argv[1]);
	if (pid_server <= 0 || !is_num(argv[1]))
		error_msg(2);
	else if (!argv[2][0])
		error_msg(3);
	ft_printf("Client PID: %d\n", pid_client);
	ft_printf("Text to send: %s\n", argv[2]);
	ft_printf("%sSending text..%s\n", YELLOW, END);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	text_sender(argv[2], pid_server);
	return (0);
}
