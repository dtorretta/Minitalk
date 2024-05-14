/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:54:35 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/11 17:54:35 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void error_msg(int i)
{
	if(i == 1)
	{
		ft_printf("%s\nError. please follow the format: <server_pid>", RED);
		ft_printf(" <text to send>\n");
		ft_printf("%s\nIf the text to send contains more than one word, ", END);
		ft_printf("please enclose it in quotes\n");
		ft_printf("\nexample: 1234 \"This is an example\"\n\n");
	}
	else if(i == 2)
		ft_printf("%s\nError: The PID must be a positive integer.\n\n", RED);
	else if(i == 3)
		ft_printf("%s\nError: Please, insert a non-empty message.\n\n", RED);
	else if(i == 4)
		ft_printf("\n%s client: unexpected error.\n", RED);
	exit (EXIT_FAILURE);
}

static int	is_num(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

//It iterates char by char
//Each char has its binary representation composed of 8 bits combining 0 and 1.
//it checks if the most significant bit (leftmost) is 1 (& 128). 
//If it's 1, it sends SIGUSR1 signal. If it's 0, it sends SIGUSR2 signal.
//(c = c << 1) moves to the next bit of the character.
//At the end, it sends the null character to indicate the end of the text.
static void char_to_bin(char *text, int s_pid)
{
	int i;
	int bit;
	
	i = -1;
	while (text[++i])
	{
		bit = 0;
		while (bit++ < 8)
		{
			if (text[i] & 128)
			{
				if (kill(s_pid, SIGUSR1) == -1)
					error_msg(4);
			}
			else
			{
				if (kill(s_pid, SIGUSR2) == -1)
					error_msg(4);
			}
			text[i] = text[i] << 1;
			pause();
			usleep(100);
		}		
	}
	char_to_bin('\0', s_pid);
}

//When SIGUSR2 is received, it just increases a received signals counter. 
//Until SIGUSR1 is received, it means that not all the text has been sent.
//When SIGUSR1 is received, the signals were successfully sent.
static void    signal_handler(int sig) 
{
	static int signal;
	
	signal = 0;
	if (sig == SIGUSR1)
	{
		ft_printf("\n%s%d Signals sent successfully!\n", GREEN, ++signal);
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGUSR2)
		signal++;
}

//Error managing: cero/negativ PID or non numeric arguments
int main(int argc, char **argv)
{
	if (argc != 3)
		error_msg(1);

	pid_t pid_client;
	pid_t pid_server;
	
	pid_client = getpid();
	pid_server = atoi(argv[1]);
	if (pid_server <= 0 || !is_num(argv[1]))
		error_msg(2);
	else if (!argv[2][0])
		error_msg(3);
	ft_printf("Client PID: %d\n", pid_client);
	ft_printf("Text to send: %s\n", argv[2]);
	ft_printf("%sSending text..\n", YELLOW);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	char_to_bin(argv[2], pid_server);
	return (0);
}
