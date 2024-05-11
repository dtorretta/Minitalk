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


int	is_num(char *num)
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

// convierte un carácter en su representación binaria y luego envía esta representación bit a bit a través de señales de UNIX
// LO HAGO CON BINARIO PORQUE CON 0 Y 1 PUEDO ENVIAR HASTA 2 E;ALES
//cada caracter lo leo bit a bit
//se ejecuta el bucle 8 veces, una vez por cada bit en la representación binaria de c.
//verifica si el bit más significativo (izquierda) es 1 (& 128). Si es 1, envía la señal SIGUSR1. Si es 0, envía la señal SIGUSR2.
//c = c << 1; me muevo al sigueinte bit del char
//pause(); // si no le pongo el sleep hay se;ales que se pierden

void	chartobin(char c, int pid)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128) // de esta forma siempre comparo con el mas signficativo
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("\n%s client: unexpected error.\n", RED); //arreglar los printf!!!!!
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("\n%sclient: unexpected error.\n", RED);
				exit(EXIT_FAILURE);
			}
		}
		c = c << 1;
		bit++;
		pause();
		usleep(100);
	}
}

//funcion par enviar el texto ungresado como parametro
//itera caracter por caracter y llama a la funcion chartobin para transformarlo en binario
// al final tengo que enviar el null caracter para indicar el fin del texto a enviar
void text_sender(char *text, int s_pid)
{
	int i = 0;
	while (text[i])
	{
		chartobin(text[i], s_pid);
		i++;
	}
	chartobin('\0', s_pid);
}

//Cuando recibe la señal SIGUSR2, simplemente incrementa un contador de señales recibidas. 
//Hasta que no se recibe SIGUSR1, significa que o se envio todo el texto.
//Cuando recibe la señal SIGUSR1, las señales se enviaron con éxito y termina el programa (EXIT_SUCCESS). 
void	signal_handler(int sig)
{
	static int signal = 0;

	if (sig == SIGUSR1)
	{
		printf("\n%s%d Signals sent successfully!\n", GREEN, ++signal);
			// aumenta antes para por lo menos enviar 1
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGUSR2)
		signal++;
}

//error managing: negativ PID or non numeric arguments
int	main(int argc, char **argv)
{
	pid_t pid_client = getpid();
	pid_t pid_server = atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("%sError. please follow the format: <server_pid> <text to send>\n",RED);
		ft_printf("If the text to send contains more than one word, please enclose it in quotes\n");
		ft_printf("example: 1234 \"This is an example\"\n");
		return (EXIT_FAILURE);
	}
	else
	{
		// si es 0 o negativo esta mal (o deberia aceptar 0)??
		if (pid_server < 0 || !is_num(argv[1]))
		{
			ft_putendl_fd(("%sError: The PID must be a positive integer.\n", RED), 2);
			return (EXIT_FAILURE);
		}
		if (!argv[2][0])
		{
			ft_printf("%sError: Please, insert a non-empty message.\n", RED);
			return (EXIT_FAILURE);
		}
		ft_printf("Cliente PID: %d\n", pid_client);
		ft_printf("Text to send: %s\n", argv[2]);
		ft_printf("%sSending text..\n", YELLOW);
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		text_sender(argv[2], pid_server);
	}
	return (0);
}

