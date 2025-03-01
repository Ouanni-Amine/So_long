/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:08:53 by aouanni           #+#    #+#             */
/*   Updated: 2024/10/28 18:18:23 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;
	size_t			s;

	s = size * count;
	if (count != 0 && size != 0 && s / count != size)
		return (NULL);
	i = 0;
	p = (unsigned char *)malloc(s);
	if (p == NULL)
		return (NULL);
	while (i < s)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
