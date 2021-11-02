/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:48:58 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 12:49:02 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		is_valid;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = -1;
	j = 0;
	while (++i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			is_valid = 1;
			while (needle[j])
			{
				if (needle[j] != haystack[i + j] || i + j >= len)
					is_valid = 0;
				j++;
			}
			if (is_valid == 1)
				return ((char *)haystack + i);
			j = 0;
		}
	}	
	return (NULL);
}
