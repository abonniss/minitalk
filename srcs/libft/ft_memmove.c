/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:52:34 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 11:32:14 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst_cp++ = *src_cp++;
	}
	else
	{
		while (len--)
			*(dst_cp + len) = *(src_cp + len);
	}
	return (dst);
}
