/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 06:21:07 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/03 08:02:08 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitnumber(char const *s, char c)
{
	int	dn;
	int	a;
	int	isword;

	a = 0;
	isword = 0;
	dn = 0;
	while (s[a])
	{
		if (s[a] != c && !isword)
		{
			dn++;
			isword = 1;
		}
		else
		{
			if (s[a] == c)
				isword = 0;
		}
		a++;
	}
	return (dn);
}

static int	*getwordslen(char const *s, char c)
{
	int	*arr;
	int	a;
	int	len;
	int	b;

	arr = (int *)malloc((digitnumber(s,c) + 1) * sizeof(int));
	a = 0;
	b = 0;
	while (b < digitnumber(s, c))
	{
		len = 0;
		while (s[a] == c)
			a++;
		while (s[a] != c && s[a])
		{
			a++;
			len++;
		}
		arr[b] = len;
		b++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{

	arr = (char **)malloc(digitnumber(s, c) * sizeof(char *));
	printf("%d",getwordslen("Selam Furkan Naber?==", ' ')[3]);
	return (arr);
}
