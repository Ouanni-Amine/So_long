/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:58:41 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/28 22:06:14 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}
