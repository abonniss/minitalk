/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:42:30 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 19:34:10 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libftprintf.h"
# define CHAR_SIZE 8
# define SHIFT_VALUE '0'
# define NB_SIGS 2
# define FAILURE -1
# define SUCCESS 0
# define TIME_TO_WAIT 500
# define END_OF_TRANSMISSION 0x04
# define NB_ARGS 3
# define USAGE "usage: ./client server_pid string_to_display\n"
# define ERR_KILL "Something went wrong with pid"
# define MSG_SUCCESS "SUCCESS - End of transmission"
# define TIMEOUT 2

typedef struct s_env
{
	size_t		bit_index;
	char		current_char;
	int			client_pid;
	t_buffer	*buffer;
}				t_env;

#endif
