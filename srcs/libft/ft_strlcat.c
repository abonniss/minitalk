/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:44:47 by abonniss          #+#    #+#             */
/*   Updated: 2019/11/21 15:44:54 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	int		test;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	test = dstsize - len_dst - 1;
	while ((int)i < test && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (dstsize != 0 && dstsize > len_dst)
	{
		dst[len_dst + i] = '\0';
		return (len_dst + len_src);
	}
	else
		return (len_src + dstsize);
}
