/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:31:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 00:19:59 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

int is_num(char *num)
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

void    chartobin (char c, int pid)
{
	int	bit;
    

	bit = 0;
    while (bit < 8) 
    {
        if (c & 128) //de esta forma siempre comparo con el mas signficativo
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                printf("\n%s client: unexpected error.\n", RED);
	            exit(EXIT_FAILURE);
            }
        }            
        else
        {   
            if(kill(pid, SIGUSR2) == -1)
            {
                printf("\n%sclient: unexpected error.\n", RED);
	            exit(EXIT_FAILURE);  
            }
        }
        c = c << 1; //me muevo al sigueinte char
        bit++;
        pause(); //si no le pongo el sleep hay se;ales que se pierden
        usleep(100);
    }
}

void text_sender (char *text, int s_pid)
{
    int i = 0;

    while(text[i])
    {
        chartobin(text[i], s_pid);
        i++;
    }
    chartobin('\0', s_pid); //al final tengo que enviar el null caracter
}

void signal_handler(int sig)
{
    static int signal = 0;

    if (sig == SIGUSR1)
    {    
        printf("\n%s%d Signals sent successfully!\n", GREEN, ++signal); //aumenta antes para por lo menos enviar 1
        exit(EXIT_SUCCESS);
    }
    else if (sig == SIGUSR2)
        signal++;
}

int main (int argc, char **argv)
{
    pid_t pid_client = getpid();
    pid_t pid_server = atoi(argv[1]);
    if (argc != 3)
    {
        printf("%sError please follow the format: <server_pid> <text to send>\n", RED);
        printf("If the text to send contains more than one word, please enclose it in quotes\n");
        printf("example: 1234 \"This is an example\"\n");
        return (EXIT_FAILURE);
    }
    else
    {
        //si es 0 o negativo esta mal (o deberia aceptar 0)??
        if (pid_server < 0 || !is_num(argv[1]))
        {
            printf("%sError: The PID must be a positive integer.\n", RED);
            return (EXIT_FAILURE);
        }
        if (!argv[2][0])
        {
            printf("%sError: Please, insert a non-empty message.\n", RED);
            return (EXIT_FAILURE);
        }
        printf("Cliente PID: %d\n", pid_client);
        printf("Text to send: %s\n", argv[2]);
        printf("%sSending text..\n", YELLOW);
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
        text_sender (argv[2], pid_server);
    }
    return(0);
}
