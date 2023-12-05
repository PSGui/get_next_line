/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:52:07 by gsaladri          #+#    #+#             */
/*   Updated: 2023/11/21 15:52:15 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_open(int fd, char *pointer)
{
	char	*buff;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff = ft_bzero(buff, BUFFER_SIZE);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buff, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			free(pointer);
			return (NULL);
		}
		buff[bytes] = '\0';
		pointer = ft_strjoin(pointer, buff);
	}
	free(buff);
	return (pointer);
}

static char	*ft_line_copy(char *pointer)
{
	int		i;
	char	*buff_help;

	i = 0;
	if (pointer[0] == '\0')
		return (NULL);
	while (pointer[i] != '\n' && pointer[i])
		i++;
	buff_help = malloc((i + 2) * sizeof(char));
	if (!buff_help)
		return (NULL);
	i = 0;
	while (pointer[i] && pointer[i] != '\n')
	{
		buff_help[i] = pointer[i];
		i++;
	}
	if (pointer[i] == '\n')
	{
		buff_help[i] = pointer[i];
		i++;
	}
	buff_help[i] = '\0';
	return (buff_help);
}

static char	*ft_pointer_update(char *pointer)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	while (pointer[i] && pointer[i] != '\n')
		i++;
	if (pointer[i] == '\0')
	{
		free(pointer);
		return (NULL);
	}
	buff = malloc((ft_strlen(pointer) - i) + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (pointer[i] != '\0')
		buff[j++] = pointer[i++];
	buff[j] = '\0';
	free(pointer);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*pointer[MAX_FD];
	char		*linha;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pointer[fd] = ft_open(fd, pointer[fd]);
	if (!pointer[fd])
	{
		return (NULL);
	}
	linha = ft_line_copy(pointer[fd]);
	pointer[fd] = ft_pointer_update(pointer[fd]);
	return (linha);
}
