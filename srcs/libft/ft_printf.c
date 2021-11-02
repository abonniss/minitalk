/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:04:01 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 11:15:13 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret_value;
	char	*output;

	output = NULL;
	va_start(args, input);
	ret_value = ft_vasprintf(&output, input, args);
	va_end(args);
	if (ret_value != FAILURE)
		ret_value = write(STDOUT_FILENO, output, ret_value);
	free(output);
	return (ret_value);
}

int	ft_dprintf(int fd, const char *input, ...)
{
	va_list	args;
	int		ret_value;
	char	*output;

	output = NULL;
	va_start(args, input);
	ret_value = ft_vasprintf(&output, input, args);
	va_end(args);
	if (ret_value != FAILURE)
		ret_value = write(fd, output, ret_value);
	free(output);
	return (ret_value);
}

int	ft_asprintf(char **ret, const char *input, ...)
{
	va_list	args;
	int		ret_value;

	(void)ret;
	va_start(args, input);
	ret_value = ft_vasprintf(ret, input, args);
	va_end(args);
	return (ret_value);
}

int	ft_vasprintf(char **ret, const char *input, va_list args)
{
	int	ret_value;

	ret_value = parse_string(ret, input, args);
	return (ret_value);
}
