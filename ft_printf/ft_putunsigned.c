/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:48 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/25 10:28:20 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (ft_putchar('0'));
	if (i >= 10)
		count += ft_putunsigned(i / 10);
	ft_putchar(i % 10 + '0');
	return (count + 1);
}
