/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 14:47:48 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newcopy;

	newcopy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (newcopy == NULL)
		return (NULL);
	return (ft_strcpy(newcopy, s1));
}
