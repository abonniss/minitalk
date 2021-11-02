/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 14:46:15 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	int				len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	map = (char *)malloc(sizeof(char) * (len + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = f(i, (char)s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
