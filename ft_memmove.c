/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:17:30 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/15 00:45:28 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	char		*csrc;
	size_t		a;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	a = 0;
	if (cdest > csrc)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
	{
		while (a < n)
		{
			cdest[a] = csrc[a];
			a++;
		}
	}
	return (dest);
}
