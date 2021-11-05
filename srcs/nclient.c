/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:47:26 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/05 19:51:46 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS 0
#define FAILURE -1
#define CHAR_SIZE 8
#define 


static void send_char(const char c, const int *pid)
{
	size_t				i;
	uint8_t 			bit;
	static const int 	send_signal[]:{SIGUSR1, SIGUSR2};

	i = 0;
	bit = 0;
	while (i < CHAR_SIZE)
	{
		bit = (c >> i) & 1;
		if (kill(pid, send_signal[bit]) == FAILURE)
		{
			printf("Il y a un prob avec le serveur");
			exit(EXIT_FAILURE);
		}
		usleep(TIME_TO_WAIT);
		++i:q;
	}
}

static void	send_str(const char *str, const int *pid)
{
	size_t i;

	i = 0; 
	while (str[i] != '\0')
	{
		send_char(str[i], &pid),
		++i;
	}
}
	
int main (int argc, char **argv)
{
	int pid;

	pid = 0;
	if (argc != 3 || ft_satoi(argv[1], &pid) == FAILURE)
		return (EXIT_FAILURE)
	else 
		send_str(argv[1], &pid);
		kill(SIGKILL, pid);
	return (EXIT_SUCCESS);
}
