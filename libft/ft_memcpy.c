/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:02:06 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/15 14:48:07 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		*p1;

	i = 0;
	if (dst == src)
		return (dst);
	p = (const unsigned char *)src;
	p1 = (unsigned char *)dst;
	while (i < n)
	{
		p1[i] = p [i];
		i++;
	}
	return (dst);
}
