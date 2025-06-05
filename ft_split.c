/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 06:21:07 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/04 17:27:16 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordnumber(char const *s, char c)
{
	int	a;
	int	wd;

	a = 0;
	wd = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		if (s[a] != c)
		{
			wd++;
			while (s[a] != c && s[a])
				a++;
		}
	}
	return (wd);
}

static char	*addarr(char *s, int start, int len)
{
	int	a;
	char	*nstr;

	nstr = malloc(sizeof(char) * (len + 1));
	a = 0;
	if (!nstr)
		return (0);
	while (a < len)
	{
		nstr[a] = s[start];
		a++;
		start++;
	}
	nstr[a] = '\0';
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int	a;
	int	b;
	int	start;

	arr = (char **)malloc((wordnumber(s, c) + 1) * sizeof(char *));
	if (!arr || !s)
		return (0);
	a = 0;
	b = 0;
	start = 0;
	while (a < wordnumber(s, c))
	{
		while (s[b] == c && s[b])
			b++;
		start = b;
		while (s[b] != c && s[b])
			b++;
		if (b > start)
			arr[a] = addarr((char *)s, start, b - start);
		a++;
	}
	arr[a] = NULL;
	return (arr);
}
