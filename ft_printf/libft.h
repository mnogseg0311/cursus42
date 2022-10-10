/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:54:12 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/10 17:43:54 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int i);
void	ft_putvoidptr(unsigned long p);
void	ft_putdecimal(int n);
void	ft_putunsigdecimal(unsigned int n);
void	ft_puthexalow(unsigned int i);
void	ft_puthexaupp(unsigned int i);

#endif
