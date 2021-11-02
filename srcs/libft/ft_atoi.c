/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:28:21 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/02 09:55:33 by abonniss         ###   ########.fr       */
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

long	ft_atol(const char *str)
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


int	ft_atoi(const char *str)
{
	return (ft_atol(str));
}

int ft_satol(const char *str, long *nb)
{
	*nb = 0;
	if (ft_isnumber(str) == false)
		return (FAILURE);
	*nb = ft_atol(str);
	return (SUCCESS);
}

int ft_satoi(const char *str, int *nb)
{
	long lnb;
	int ret; 
	
	ret = ft_satol(str, &lnb);
	*nb = (int)lnb;
	return (ret);
}
