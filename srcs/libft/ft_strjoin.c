/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 14:43:05 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	int		size;
	int		i;
	int		i2;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	join_s = malloc(sizeof(char) * size + 1);
	if (join_s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join_s[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2])
	{
		join_s[i + i2] = s2[i2];
		i2++;
	}
	join_s[i + i2] = '\0';
	return (join_s);
}
