/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:20:31 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 19:28:59 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_env	g_env;

void	bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		g_env.current_char |= (0x01 << g_env.bit_index);
	++g_env.bit_index;
	g_env.client_pid = info->si_pid;
}

static void	process_byte(void)
{
	if (g_env.current_char == END_OF_TRANSMISSION)
	{
		ft_putendl_fd(g_env.buffer->string, STDOUT_FILENO);
		reset_buffer(g_env.buffer);
		kill(g_env.client_pid, SIGUSR1);
	}
	else
		push_char_buffer(g_env.buffer, g_env.current_char);
	g_env.bit_index = 0;
	g_env.current_char = '\0';
}

static void	define_signals(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = bit_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static void	loop_handler(void)
{
	while (true)
	{
		pause();
		if (g_env.bit_index == CHAR_SIZE)
			process_byte();
	}
}

int	main(void)
{	
	ft_printf("%d\n", getpid());
	bzero(&g_env, sizeof(t_env));
	g_env.buffer = create_buffer();
	define_signals();
	loop_handler();
	delete_buffer(g_env.buffer);
	return (EXIT_SUCCESS);
}
