/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:54 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/15 15:52:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// It prints the character received and checks if it is the null character.
// If so, that means that the string was fully printed.
//'signals' is set to 0, ready to receive a new string and start counting again
int	bin_to_char(char byte, int signal, int client_pid)
{
	ft_putchar_fd(byte, 1);
	if (byte == '\0')
	{
		ft_printf("\n%s%d Signals received successfully!\n\n", GREEN, signal);
		ft_printf("%s", END);
		signal = 0;
		if (kill(client_pid, SIGUSR1) == -1)
		{
			ft_printf("\n%sServer: unexpected error.%s\n", RED, END);
			exit(EXIT_FAILURE);
		}
	}
	return (signal);
}

// receive the signal SIGUSR1 --> binary number 1
// receive the signal SIGUSR2 --> binary number 0
// It concatenates the received bits until get a complete byte (8 bits).
// If a complete byte has been received, calls the function bin_to_char
// to print the byte that is in binary.
//'i' is set to 0, ready to receive again 8 bits.
void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit = 0;
	static char	byte = 0;
	static int	i = 0;
	static int	signal = 0;

	(void) context;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	signal++;
	if (i++ < 8)
		byte = (byte << 1) | bit;
	if (i == 8)
	{
		signal = bin_to_char(byte, signal, client_pid);
		i = 0;
	}
	usleep(100);
	kill(client_pid, SIGUSR2);
}

static void	print_header(int pid_server)
{
	ft_printf("\n███╗   ███╗██╗███╗   ██╗██╗███");
	ft_printf("█████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██");
	ft_printf("╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██");
	ft_printf("║   ███████║██║     █████╔╝ \n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██");
	ft_printf("║   ██╔══██║██║     ██╔═██╗ \n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██");
	ft_printf("║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ");
	ft_printf("╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n");
	ft_printf("%s                      PID: %d%s\n", RED, pid_server, END);
	ft_printf("%s              ⊱ ────────────────────── ⊰%s\n", RED, END);
}

//'while(1)' ensures that the process remains active in an infinite loop that
// is waiting (pause) to receive signals and respond to them as defined in
// SIGUSR_handler function.
// Once a signal is received, it returns to the beginning of the loop.
int	main(void)
{
	int					pid_server;
	struct sigaction	bitereceived;

	pid_server = getpid();
	print_header(pid_server);
	bitereceived.sa_sigaction = sigusr_handler;
	bitereceived.sa_flags = SA_SIGINFO;
	sigemptyset(&bitereceived.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &bitereceived, NULL);
		sigaction(SIGUSR2, &bitereceived, NULL);
		pause();
	}
	return (0);
}
