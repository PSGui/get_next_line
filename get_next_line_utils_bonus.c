/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:55:40 by gsaladri          #+#    #+#             */
/*   Updated: 2023/11/21 15:55:41 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_bzero(void *ptr, size_t x)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < x)
	{
		p[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1); 
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*str_join;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(str) + ft_strlen(buffer);
	str_join = malloc((size + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		str_join[i] = str[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j])
		str_join[i++] = buffer[j++];
	str_join[i] = '\0';
	free(str);
	return (str_join);
}
