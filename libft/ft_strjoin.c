/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:40:56 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/02 11:45:58 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(const char *s, char *p)
{
	while (*s != '\0')
	{
		*p = *s;
		p++;
		s++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*p;
	char	*r;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1len + s2len +1));
	if (p == NULL)
		return (NULL);
	r = p;
	p = fill(s1, p);
	p = fill(s2, p);
	*p = '\0';
	return (r);
}
