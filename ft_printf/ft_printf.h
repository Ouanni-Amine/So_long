/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:57:24 by aouanni           #+#    #+#             */
/*   Updated: 2024/11/28 21:54:32 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_puthexalow(unsigned int i);
int		ft_puthexaupp(unsigned int i);
int		ft_putptr(void *ptr);
int		ft_putchar(char c);
int		ft_putunsigned(unsigned int n);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);
size_t	ft_putstr(const char *s);

#endif