/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:55:51 by gsaladri          #+#    #+#             */
/*   Updated: 2023/11/21 15:55:52 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*get_next_line(int fd);
void	*ft_bzero(void *ptr, size_t x);
char	*ft_strjoin(char *str, char *buffer);

#endif
