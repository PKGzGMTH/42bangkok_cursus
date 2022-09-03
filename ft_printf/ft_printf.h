/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:04:10 by ptippaya          #+#    #+#             */
/*   Updated: 2022/09/03 17:23:03 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(size_t n);
int	ft_putubase(size_t n, char *s, int *count);
int	ft_putbase(ssize_t n, char *s, int *count);
int	ft_putptr(size_t n);
int	ft_putdec(int n);
int	ft_putudec(unsigned int n);
int	ft_puthexl(size_t n);
int	ft_puthexu(size_t n);

int	ft_printf_format(char c, va_list arg);
int	ft_printf(const char *format, ...);

#endif
