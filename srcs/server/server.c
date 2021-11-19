/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:20:31 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/18 09:16:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_env 		env;

void bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext; 
	if (sig == SIGUSR1)
		env.current_char |= (0x01 << env.bit_index);
	++env.bit_index;
	env.client_pid = info->si_pid;
}

static void process_byte(void)
{
	if (env.current_char == END_OF_TRANSMISSION)
	{
		ft_putendl_fd(env.buffer->string, STDOUT_FILENO);
		reset_buffer(env.buffer);
		kill(env.client_pid, SIGUSR1);
	}
	else 
		push_char_into_str_manager(env.buffer, env.current_char);
	env.bit_index = 0;
	env.current_char = '\0';
}

static void define_signals(void)
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = bit_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static void loop_handler(void)
{
	while (true)
	{
		pause();
		if (env.bit_index == CHAR_SIZE)
			process_byte();
	}
}

int main(void)
{	
	ft_printf("%d\n", getpid());
	bzero(&env, sizeof(t_env));
	env.buffer = create_struct_buffer();	
	define_signals();
	loop_handler();
	delete_struct_buffer(env.buffer);
	return (EXIT_SUCCESS);
}
