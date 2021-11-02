/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:49:58 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 12:50:01 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i != -1 && last == NULL)
	{
		if (s[i] == c)
		{
			last = (char *)s + i;
			break ;
		}
		i--;
	}
	if (last)
		return (last);
	return (NULL);
}
