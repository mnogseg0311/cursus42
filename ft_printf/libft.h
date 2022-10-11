/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:51:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/11 15:47:20 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int i);
int	ft_putvoidptr(unsigned long p);
int	ft_putunsigdecimal(unsigned int n);
int	ft_puthexalow(unsigned int i);
int	ft_puthexaupp(unsigned int i);

#endif
