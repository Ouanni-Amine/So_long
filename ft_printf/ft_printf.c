/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:57:03 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/30 11:19:06 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list list, char F)
{
	int	count;

	count = 0;
	if (F == 's')
		count = (ft_putstr(va_arg(list, const char *)));
	else if (F == 'c')
		count = (ft_putchar((char)va_arg(list, int)));
	else if (F == 'd' || F == 'i')
		count = (ft_putnbr(va_arg(list, int)));
	else if (F == 'X')
		count = (ft_puthexaupp(va_arg(list, unsigned int)));
	else if (F == 'x')
		count = (ft_puthexalow(va_arg(list, unsigned int)));
	else if (F == 'u')
		count = (ft_putunsigned(va_arg(list, unsigned int)));
	else if (F == 'p')
	{
		write (1, "0x", 2);
		count = (2 + ft_putptr(va_arg(list, void *)));
	}
	else
		count += ft_putchar(F);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			count += write (1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_format(list, str[i]);
		}
		i++;
	}
	va_end(list);
	return (count);
}
