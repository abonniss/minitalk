/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:42:25 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 16:12:20 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_add_prefix(char **input, const char *prefix)
{
	size_t	len_input;
	size_t	len_prefix;
	char	*output;

	if (input == NULL || prefix == NULL)
		return (FAILURE);
	len_prefix = ft_strlen(prefix);
	len_input = ft_strlen(*input);
	output = (char *)ft_calloc(len_prefix + len_input + 1, sizeof(char));
	if (output == NULL)
		return (FAILURE);
	ft_memmove(output, prefix, len_prefix);
	ft_memmove(output + len_prefix, *input, len_input);
	free(*input);
	*input = output;
	return (SUCCESS);
}
