/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:51:47 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 15:52:16 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int i);
int		ft_putvoidptr(unsigned long p);
int		ft_putunsigdecimal(unsigned int n);
int		ft_puthexalow(unsigned int i);
int		ft_puthexaupp(unsigned int i);
size_t	ft_strlen(const char *s);

#endif
