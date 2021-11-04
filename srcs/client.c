/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:56:34 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/04 08:45:17 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define CHAR_SIZE 8
#define SHIFT_VALUE '0'
#define NB_SIGS 2
#define FAILURE -1
#define SUCCESS 0
#define TIME_TO_WAIT 500
#define END_OF_TRANSMISSION 0x04
#define NB_ARGS 3
#define USAGE "usage: ./client server_pid string_to_display\n"
#define ERR_KILL "Something went wrong with pid"
#define MSG_SUCCESS "SUCCESS - End of transmission"
#define TIMEOUT 2

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
			dprintf(STDERR_FILENO1, "%s = %d\n", ERR_KILL, server_pid);
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
	print_bit(server_pid, END_OF_TRANSMISSION);
}

void		trigger_success(int sig)
{
	putendl(MSG_SUCCESS);
	exit(EXIT_SUCCESS);
}

static int		set_signals(void)
{
	signal(SIGUSR1, trigger_success);
	signal(SIGUSR2, trigger_success);
}

int		main(int ac, char **av)
{
	int server_pid;

	if (ac != NB_ARGS || ft_satoi(av[1], &server_pid) == FAILURE)
		dprintf(STDERR_FILENO, USAGE);
	else
	{
		set_signals();
		send_str(server_pid, av[2]);
		putendl("Wait response from server...");	
		sleep(TIMEOUT);
		putendl("Kill server...");
		if (kill(server_pid, SIGKILL) == FAILURE)
			dprintf(STDERR_FILENO1, "%s = %d\n", ERR_KILL, server_pid);
	}
	return (EXIT_FAILURE);
}
