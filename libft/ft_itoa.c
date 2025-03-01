/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:01:11 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/04 08:48:58 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count(int n)
{
	int			c;
	int long	k;

	c = 1;
	k = n;
	if (k < 0)
		k *= -1;
	while (k / 10 > 0)
	{
		k = k / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int			is_negative;
	int			len;
	char		*p;
	long int	k;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	k = n;
	len = is_negative + count(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (is_negative == 1)
		k *= -1;
	while (len > 0)
	{
		p[len - 1] = (k % 10) + '0';
		k = k / 10;
		len--;
	}
	if (is_negative == 1)
		p[len] = '-';
	return (p);
}
