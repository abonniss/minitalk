/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:37:02 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 11:32:46 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_buff_space(t_buffer *str_buff)
{
	char	*bigger_string;

	str_buff->max_buffer_size += BUFF_SIZE;
	bigger_string = (char *)malloc(sizeof(char) * str_buff->max_buffer_size);
	if (bigger_string != NULL)
	{
		ft_bzero(bigger_string, str_buff->max_buffer_size);
		ft_memmove(bigger_string, str_buff->string,
			str_buff->current_buffer_size);
		free(str_buff->string);
		str_buff->string = bigger_string;
		return (SUCCESS);
	}
	return (FAILURE);
}

int	push_str_into_str_manager(t_buffer *str_buff,
	const char *str, const size_t len_str)
{
	while (str_buff->current_buffer_size + len_str >= str_buff->max_buffer_size)
		if (add_buff_space(str_buff) == FAILURE)
			return (FAILURE);
	ft_memmove(str_buff->string + str_buff->current_buffer_size, str, len_str);
	str_buff->current_buffer_size += len_str;
	return (SUCCESS);
}

int	push_char_into_str_manager(t_buffer *str_buff, char c)
{
	return (push_str_into_str_manager(str_buff, &c, 1));
}

void	delete_struct_buffer(t_buffer *str_buff)
{
	free(str_buff->string);
	free(str_buff);
}

t_buffer	*create_struct_buffer(void)
{
	t_buffer	*str_buff;

	str_buff = malloc(sizeof(t_buffer));
	if (str_buff != NULL)
	{
		str_buff->max_buffer_size = BUFF_SIZE;
		str_buff->current_buffer_size = 0;
		str_buff->string = (char *)malloc(sizeof(char) * BUFF_SIZE);
		if (str_buff->string != NULL)
			ft_bzero(str_buff->string, str_buff->max_buffer_size);
		else
		{
			free(str_buff);
			str_buff = NULL;
		}
	}
	return (str_buff);
}
