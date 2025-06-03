/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:35:07 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/05/31 14:57:34 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dstchr;
	char	*srcchr;
	size_t	a;

	if (!dest && !src)
		return (NULL);
	dstchr = (char *)dest;
	srcchr = (char *)src;
	a = 0;
	while (a < n)
	{
		dstchr[a] = srcchr[a];
		a++;
	}
	return (dest);
}
