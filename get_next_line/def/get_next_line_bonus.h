/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:40:04 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/26 19:58:41 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUe_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*emptyline(char *str);
char	*get_next_line(int fd);
char	*getdata(char *str, int fd);
char	*nicefree(char **ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char	*s2);
int		ft_strlen(char *str);

#endif
