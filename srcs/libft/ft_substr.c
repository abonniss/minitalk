/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 12:40:46 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!s || (start >= (unsigned int)ft_strlen(s)))
	{
		sub_str = malloc(sizeof(char) * 1);
		if (sub_str == NULL)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	i = 0;
	sub_str = malloc(sizeof(char) * 1);
	if (sub_str == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
