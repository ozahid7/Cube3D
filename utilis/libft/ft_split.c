/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:43 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 09:53:51 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		p = (char *)malloc(ft_strlen(s) - start);
	else
		p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	ft_compteur(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
		{
			if (s[j + 1] == c || s[j + 1] == '\0')
				k++;
			j++;
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (k);
}

static int	ft_iter(char const *s, int i, int j)
{
	if (s[j] == '\0')
	{
		i = j;
	}
	else
	{
		i = j + 1;
	}
	return (i);
}

static char	**ft_remp(char **p, char const *s, char c)
{
	int	i;
	int	j;
	int	tab;

	i = 0;
	tab = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (*(s + i) != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (s[i] != c)
		{
			p[tab] = ft_substr(s, i, j - i);
			if (!p[tab])
				return (free2d(p), NULL);
			tab++;
		}
		i = ft_iter(s, i, j);
	}
	p[tab] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	p = (char **)malloc((ft_compteur(s, c) + 1) * sizeof(char *));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	if (ft_remp(p, s, c) == NULL)
		return (NULL);
	return (p);
}
