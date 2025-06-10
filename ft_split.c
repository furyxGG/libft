/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 06:21:07 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 00:49:10 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordnumber(char const *s, char c)
{
	int	a;
	int	wd;

	a = 0;
	wd = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		if (s[a] != c && s[a])
		{
			wd++;
			while (s[a] != c && s[a])
				a++;
		}
	}
	return (wd);
}

static char	*ft_addarr(char *s, int start, int len)
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

static void	ft_free(char **arr)
{
	int	a;

	a = 0;
	while (arr[a++])
		free(arr[a]);
	free(arr);
}

static int	ft_wlenght(char const *s, char c)
{
	int	a;

	a = ft_strchr(s, c) - s;
	if (!ft_strchr(s, c))
		return (ft_strlen(s));
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int	a;
	int	wc;

	wc = ft_wordnumber(s, c);
	arr = (char **)malloc((wc + 1) * sizeof(char *));
	a = 0;
	if (!arr || !s)
		return (NULL);
	while (wc--)
	{
		while (*s == c && *s)
			s++;
		if (*s != c)
		{
			arr[a] = ft_addarr((char *)s, 0, ft_wlenght(s, c));
			if (!arr[a++])
				ft_free(arr);
			while (*s != c && *s)
				s++;
		}
	}
	arr[a] = NULL;
	return (arr);
}
