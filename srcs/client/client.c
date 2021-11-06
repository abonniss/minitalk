/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:56:34 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/06 18:47:09 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(const int server_pid, const char c)
{
	static const int sig[NB_SIGS] = {SIGUSR2, SIGUSR1};
	size_t	i;
	uint8_t bit;

	i = 0;
	while (i < CHAR_SIZE)
	{
		bit = (c >> i) & 0x01;
		if (kill(server_pid, sig[bit]) == FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "%s = %d\n", ERR_KILL, server_pid);
			exit(EXIT_FAILURE);
		}
		usleep(TIME_TO_WAIT);
		++i;
	}
}

static void	send_str(const int server_pid, const char * const str)
{
	size_t i; 

	i = 0;
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		++i;
	}
	send_char(server_pid, END_OF_TRANSMISSION);
}

void		trigger_success(int sig)
{
	(void)sig;
	ft_putendl_fd(MSG_SUCCESS, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

static void		set_signals(void)
{
	signal(SIGUSR1, trigger_success);
	signal(SIGUSR2, trigger_success);
}

int		main(int ac, char **av)
{
	int server_pid;

	if (ac != NB_ARGS || ft_satoi(av[1], &server_pid) == FAILURE)
		ft_putendl_fd(USAGE, STDERR_FILENO);
	else
	{
		set_signals();
		send_str(server_pid, av[2]);
		ft_putendl_fd("Wait response from server...", STDOUT_FILENO);	
		sleep(TIMEOUT);
		ft_putendl_fd("Kill server...", STDOUT_FILENO);
		if (kill(server_pid, SIGKILL) == FAILURE)
			ft_dprintf(STDERR_FILENO, "%s = %d\n", ERR_KILL, server_pid);
	}
	return (EXIT_FAILURE);
}
