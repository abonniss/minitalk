/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_duixx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:58:43 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 12:02:29 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conv_di(va_list args, char **output)
{
	int	ret;
	int	lnbr;

	lnbr = (int)va_arg(args, long);
	*output = ft_ltoa_base(lnbr, 10);
	ret = 0;
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}

int	conv_u(va_list args, char **output)
{
	int				ret;
	unsigned int	lnbr;

	lnbr = (unsigned int)va_arg(args, unsigned long);
	*output = ft_ultoa_base(lnbr, 10);
	ret = 0;
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}

int	conv_x(va_list args, char **output)
{
	int	ret;

	ret = conv_x_big(args, output);
	if (*output != NULL)
		*output = ft_str_to_lowercase(*output);
	return (ret);
}

int	conv_x_big(va_list args, char **output)
{
	int				ret;
	unsigned long	lnbr;

	lnbr = va_arg(args, unsigned int);
	*output = ft_ultoa_base(lnbr, 16);
	ret = 0;
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}
