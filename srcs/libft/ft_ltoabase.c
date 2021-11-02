/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:06:10 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 15:05:47 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len_nbr(unsigned long number, const int base_number)
{
	size_t	len;

	if (number == 0)
		return (1);
	len = 0;
	while (number > 0)
	{
		number /= base_number;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long number, const int base_number)
{
	char		*output;
	size_t		len;
	size_t		index;

	if (base_number < MIN_BASE || base_number > MAX_BASE
		|| ft_strlen(CHARSET_MAX_BASE) != MAX_BASE)
		return (NULL);
	len = get_len_nbr(number, base_number);
	output = (char *)ft_calloc(len + 1, sizeof(char));
	if (output != NULL)
	{
		index = 0;
		while (number >= 0 && index < len)
		{
			output[len - 1 - index] = CHARSET_MAX_BASE[number % base_number];
			number /= base_number;
			index++;
		}
	}
	return (output);
}

char	*ft_ltoa_base(long number, const int base_number)
{
	char	*output;
	char	*tmp_output;
	size_t	len_output;

	output = ft_ultoa_base(ft_absolute(number), base_number);
	if (output == NULL || number >= 0)
		return (output);
	tmp_output = output;
	len_output = ft_strlen(output);
	output = (char *)ft_calloc(len_output + 1 + NEG, sizeof(char));
	if (output != NULL)
	{
		output[0] = NEG_SIGN;
		ft_memmove(output + NEG, tmp_output, len_output);
	}
	free(tmp_output);
	return (output);
}

char	*ft_itoa_base(int number, const int base_number)
{
	return (ft_ltoa_base(number, base_number));
}

char	*ft_itoa_2(int number)
{
	return (ft_itoa_base(number, 10));
}
