/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:42:25 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 16:10:58 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_lowercase(char *str)
{
	size_t			i;
	const size_t	len = ft_strlen(str);

	i = 0;
	while (i < len)
	{
		if (ft_is_uppercase(str[i]) == true)
			str[i] = ft_to_lowercase(str[i]);
		++i;
	}
	return (str);
}
