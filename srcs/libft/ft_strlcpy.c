/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:44:28 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 12:44:35 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize > ft_strlen(src))
		dst[ft_strlen(src)] = '\0';
	else
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
