/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:28:21 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 12:43:10 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\r')
		|| (c == '\v') || (c == '\f') || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		signe;
	long	number;

	while (ft_isspace(*str))
		str++;
	signe = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number *= signe);
}
