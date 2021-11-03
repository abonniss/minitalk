/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:46:09 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 15:55:32 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	letter_state(char c, t_state_machine *machine, va_list args)
{
	(void)args;
	if (c == '%')
		machine->state = E_CONV;
	else
		push_char_into_str_manager(machine->buffer, c);
	return (1);
}

int	conv_state(char c, t_state_machine *machine, va_list args)
{
	char							*conv_ptr;
	size_t							conv_index;
	char							*output;
	size_t							ret;
	static const t_conv_function	conv_function[] = {conv_c, conv_s, conv_p,
		conv_di, conv_u, conv_di,
		conv_x, conv_x_big, conv_percent};

	output = NULL;
	conv_ptr = ft_strchr(CONV_CHARSET, c);
	if (conv_ptr != NULL)
	{
		conv_index = conv_ptr - CONV_CHARSET;
		ret = conv_function[conv_index](args, &output);
	}
	else
		ret = conv_error(&output, c);
	if (output != NULL)
		push_str_into_str_manager(machine->buffer, output, ret);
	free(output);
	machine->state = E_LETTER;
	return (1);
}

char	*dup_buffer(t_buffer *buffer)
{
	char	*str_dup_buffer;

	str_dup_buffer = (char *)ft_calloc(buffer->current_buffer_size + 1,
			sizeof(char));
	if (str_dup_buffer != NULL)
	{
		ft_memmove(str_dup_buffer, buffer->string, buffer->current_buffer_size);
		str_dup_buffer[buffer->current_buffer_size] = '\0';
	}
	return (str_dup_buffer);
}

int	parse_string(char **output, const char *input, va_list args)
{
	t_state_machine					machine;
	static const t_state_function	state_function[] =
									{letter_state, NULL, conv_state};
	size_t							i;
	int								ret;

	i = 0;
	ft_bzero(&machine, sizeof(t_state_machine));
	machine.state = E_LETTER;
	machine.buffer = create_struct_buffer();
	while (input[i] != '\0')
		i += state_function[machine.state](input[i], &machine, args);
	*output = dup_buffer(machine.buffer);
	ret = (int)machine.buffer->current_buffer_size;
	if (*output == NULL)
		ret = 0;
	delete_struct_buffer(machine.buffer);
	return (ret);
}
