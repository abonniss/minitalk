/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:47:26 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/04 19:14:52 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define FAILURE 1
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main (int argc, char **argv)
{
	int pid;:w

	pid = 0;
	if (argc != 3 || ft_satoi(argv[1], pid) == FAILURE)
		return (EXIT_FAILURE)
	else 
		send_str(argv[1], pid);	
}
