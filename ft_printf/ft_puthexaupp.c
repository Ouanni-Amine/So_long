/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaupp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:02 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/26 11:04:54 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexaupp(unsigned int i)
{
	int	count;

	count = 0;
	if (i >= 16)
		count = ft_puthexaupp(i / 16);
	if (i % 16 >= 10 && i % 16 <= 15)
		ft_putchar((i % 16) + 55);
	else
		ft_putchar((i % 16) + '0');
	return (count + 1);
}
