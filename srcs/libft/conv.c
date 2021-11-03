/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:58:43 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 14:50:30 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conv_error(char **output, char c)
{
	int	ret;

	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = c;
	ret = 1;
	return (ret);
}

int	conv_c(va_list args, char **output)
{
	int	ret;
	int	c;

	c = va_arg(args, int);
	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = (unsigned char)c;
	ret = 1;
	return (ret);
}

int	conv_s(va_list args, char **output)
{
	int		ret;
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = NULL_STRING;
	ret = 0;
	*output = ft_strdup(str);
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}

int	conv_p(va_list args, char **output)
{
	int				ret;
	unsigned long	lnbr;

	lnbr = va_arg(args, unsigned long);
	*output = ft_ultoa_base(lnbr, 16);
	ret = 0;
	if (*output != NULL)
	{
		ret = ft_strlen(*output);
		if (ft_add_prefix(output, HEXA_PREFIX) == FAILURE)
			ret = 0;
		else
		{
			ret += ft_strlen(HEXA_PREFIX);
			*output = ft_str_to_lowercase(*output);
		}
	}
	return (ret);
}

int	conv_percent(va_list args, char **output)
{
	int	ret;

	(void)args;
	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = '%';
	ret = 1;
	return (ret);
}
