/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:46:23 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 23:50:33 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef FT_MINITALK_H
# define FT_MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
# include "libft/libft.h"


void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *s, size_t n);
int	ft_isdigit(int c);
int	is_num(char *num);

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE_COLOR "\033[34m"


#endif