/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:05:01 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/22 14:26:31 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strfree(char **tab, int count)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i < count)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

static int	nw(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	nl(char const *s, char c)
{
	int		size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i[3];

	tab = ft_calloc(sizeof(char), sizeof(tab));
	if (nw(s, c) == -1 || tab == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] == c)
			i[0]++;
		else
		{
			tab[i[1]] = (malloc(sizeof(tab) * (nl(s + i[0], c) + 1)));
			if (tab[i[1]] == NULL)
				return (ft_strfree(tab, (nw(s, c) + 1)));
			i[2] = 0;
			while (s[i[0]] && s[i[0]] != c)
				tab[i[1]][i[2]++] = s[i[0]++];
			tab[i[1]][i[2]] = '\0';
			i[1]++;
		}
	}
	return (tab);
}
