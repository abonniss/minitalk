/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:20:31 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/13 18:15:48 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
		printf("recu bit = 1");
	printf("recu bit = 0");
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
	loop_handler();
	return (0);
}
