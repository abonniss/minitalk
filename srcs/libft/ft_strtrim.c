/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:27:26 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 14:21:48 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	int		len;
	int		front_i;
	int		i;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	trim_s = ft_calloc((len + 1), sizeof(char));
	if (trim_s == NULL)
		return (NULL);
	front_i = 0;
	while (s1[front_i] && ft_ischarset(s1[front_i], set))
		front_i++;
	if (front_i == len)
		return (ft_strdup(""));
	while (s1[len - 1] && ft_ischarset(s1[len - 1], set))
		len--;
	i = 0;
	while (front_i <= len - 1)
	{
		trim_s[i] = s1[front_i++];
		i++;
	}
	return (trim_s);
}
