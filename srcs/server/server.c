/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:20:31 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/16 18:44:59 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_bufferm
{
	char c;
	char str[10];
	int buffer;
}			t_bufferm;

t_bufferm manage_buff;

size_t bithandler_i = 0; 
size_t addchar_i = 0;

void add_char_str()
{
	addchar_i = 0;

	manage_buff.str[addchar_i] = manage_buff.c;
	++addchar_i;
	ft_putendl_fd(manage_buff.str, 1);
}


void bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	char str[10];

	if (sig == SIGUSR1)
	{	
		(manage_buff.c << bithandler_i) & 0x01;
		/*ft_putendl_fd("recu bit = 1", 1);*/
		bithandler_i += 1;
	}
	else
	{
		bithandler_i += 1;
		/*ft_putendl_fd("recu bit = 0", 1);*/
	}
	if (bithandler_i == 8)
	{
		add_char_str();
		bithandler_i = 0;
		manage_buff.c = '0';
	}

}

void define_signals()
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = bit_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void loop_handler()
{
	while (true);
}

int main(void)
{
	define_signals();
	/*bzero(manage_buff)*/
	loop_handler();
	return (0);
}
