/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:19:27 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 00:10:48 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

/*al usar static, las variables (bit, byte, e i) mantienen su valor 
entre las llamadas a la función. Esto significa que, por ejemplo, si i se incrementó a 8 en una 
llamada, conservará ese valor en la próxima llamada.*/

void	SIGUSR_handler(int sig, siginfo_t *info, void *context)
{
    static int	client_pid;
    static int bit = 0;
    static char byte = 0;
    static int i = 0; 
    static int signal = 0;   // se trata de cada llamada al hanfler dentro de un mismo envio de argumentos
    (void)context;

    client_pid = info->si_pid;
    if(sig == SIGUSR1)
        bit = 1;
    else if(sig == SIGUSR2)
        bit = 0;
    
    signal++;
    if (i < 8) //probar poniendo ++i 
    {
        byte = (byte << 1) | bit; 
        i++;
    }
    if (i == 8)
    {
        ft_putchar_fd(byte, 1);
        if (byte == '\0') //se;al de que se termino de imprimir todo
        {
            //printf("check.\n");
            printf("\n%s%d Signals received successfully!\n", GREEN, signal);
            byte = 0;
            i = 0;
            signal = 0; //no puedo dorectamente quitarle el static int
            if (kill(client_pid, SIGUSR1) == -1)
            {
                printf("\n%sServer: unexpected error.\n", RED);
	            exit(EXIT_FAILURE);  
            }
            return; //no hay nada mas que recibir
        }
        i = 0; //si no es el caracter nulo, tiene que pasar a recibir el sigueinte carcter, entonces reiniciamos el contador.
         //no hace falta reiniciar byte porque va a irlo sobreescribiendo 
     }    
     usleep(100); //porque el usleep?
     kill(client_pid, SIGUSR2);
}


int main (void)
{
    //print banner
    int pid_server = getpid();
    
    printf("\n███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
    printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
    printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
    printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
    printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
    printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n");
    printf("%s                        PID: %d\n", RED, pid_server);
    printf("%s                ⊱ ────────────────────── ⊰\n", RED);
    
    struct sigaction	bitereceived;
    bitereceived.sa_sigaction = SIGUSR_handler;
    bitereceived.sa_flags = SA_SIGINFO;
    sigemptyset(&bitereceived.sa_mask);

    while(1)
    {
        sigaction(SIGUSR1, &bitereceived, NULL);
        sigaction(SIGUSR2, &bitereceived, NULL);
        pause(); //pausamos hasta que se reciba otra se;al
    }

    return(0);
}
