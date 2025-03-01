/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:26 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/25 14:02:21 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		count ++;
		n *= -1;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr (n / 10);
		count += ft_putnbr (n % 10);
	}
	else
		return (ft_putchar(n % 10 + '0'));
	return (count);
}
