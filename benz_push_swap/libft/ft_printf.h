/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:43:56 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/24 22:05:42 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putchar_f(int c, int flag, int digit);
int	ft_putstr_f(const char *str, int flag, int digit);
int	ft_putvoid_f(void *ptr, int flag, int digit);
int	ft_putnbr_f(int nbr, int flag, int digit);
int	ft_putnbr_f2(int nbr, int flag, int digit, int nbd);
int	ft_putnbr_f56(long int nb, int flag, int nbd);
int	ft_und(unsigned long int un, int b);
int	ft_putunb(unsigned long int un, int b, int c);
int	ft_putunb_f(unsigned int unb, int flag, int digit);
int	ft_puthex_f(unsigned int hex, int x, int flag, int digit);
int	ft_puthex_f4(unsigned long int hexl, int x, int flag, int hex_d);

#endif
