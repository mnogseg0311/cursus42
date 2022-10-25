/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:52 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/25 19:53:14 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*strdupvar(char *str, char c);
char 	*getdata(char *str, int fd);
int		checkline(char *str);
char		*emptyline(char *str);
int		strlenvar(char *str, char c);
void	strcpyvar(char *dst, char *src, int i, int size);
char 	*ft_strchr(const char *s, int c);
char 	*ft_strjoin(char *s1, char*s2); 
#endif
