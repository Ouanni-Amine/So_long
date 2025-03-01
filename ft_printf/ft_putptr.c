/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:33 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/28 22:06:19 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlonghexalow(unsigned long i)
{
	int	count;

	count = 0;
	if (i >= 16)
		count = ft_putlonghexalow(i / 16);
	if (i % 16 >= 10 && i % 16 <= 15)
		ft_putchar((i % 16) + 87);
	else
		ft_putchar((i % 16) + '0');
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	return (ft_putlonghexalow(address));
}
