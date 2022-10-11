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
