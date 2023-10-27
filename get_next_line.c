/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:39:22 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/27 15:39:23 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Funcao ft_open - Parametros: O file descriptor (fd)
//	Tem como objetivo alocar memoria para a variavel buff utilizando o BUFFER_SIZE.
//		Depois de esta ser alocada, ira ser preenchida com o conteudo do FD.
//			Retorna o buff com o conteudo do FD.

static char	*ft_open(int fd)
{
	char	*buff;
	int	bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return(NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes < 0) // < ------ Verificar se o ficheiro leu alguma coisa, caso nao tenha acontecido, liberta o buff
	{
		free(buff);
		return (NULL);
	}
	if (bytes == 0)
		return (0);
	buff[bytes] = '\0';
	return (buff);
}

// Funcao ft_line_search - Parametros: O buff que foi preenchido previamente e um **pointer responsavel por manter a localizacao do fim a ultima linha
//	Tem como objetivo ler a linha ate que \n seja encontrado. Utilizando i aloca a memoria necessaria para o buff_help.
//		Passa o onteudo de buff para buff_help e certifica-se que o pointer esta a apontar para a linha a seguir ao \n.
//			Retorna o buff_help que contem o conteudo da linha lida.

static char	*ft_line_search(char *buff, char **pointer)
{
	int	i;
	int	j;
	char	*buff_help;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	buff_help = (char *)malloc(i + 1);
	if (!buff_help)
		return (0);
	while (j < i)
	{
		buff_help[j] = buff[j];
		j++;
	}
	buff_help[j] = '\0';
	if (buff[i] == '\n')
		*pointer = &buff[i + 1]; // < ------ Se onde paramos foi o \n entao o pointer vai ficar a apontar para a proxima linha
	else
		*pointer = NULL; // < ------ Caso contrario o ficheiro acabou e o ponteiro passa a NULL (que depois e usado na get_next_line)
	return (buff_help);
}

// Funcao get_next_line - Parametros: O file descriptor (que neste caso e "textfile.txt").
//	1 - Verfica se o fd e menor que 0 (meaning que houve um erro) ou se o BUFFER_SIZE e menor ou igual a 0 (porque nao existem tamanhos negativos :D).
//		2 - Verifica se o pointer existe e se este for '\0', liberta-o e fica NULL para indicar que ja nao existe mais nada para ler.
//			3 - Verifica se o pointer e nulo (neste caso depende da funcao ft_line_search que verifica se o buff chegou ao fim, isto e, se nao 
//			for a primeira vez que esta a ser chamada), caso seja vai comecar o processo de abrir o ficheiro e chama a ft_line_search que retorna a linha
//				4 - Caso entre no else, significa que o ficheiro ainda na acabou e vai continuar onde ficou.

char	*get_next_line(int fd)
{
	static char	*pointer;
	char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (pointer && *pointer == '\0')
	{
		free(pointer);
		pointer = NULL;
	}
	if (!pointer)
	{
		buff = ft_open(fd);
		if (!buff)
			return (NULL);
		return (ft_line_search(buff, &pointer));
	}
	else
		return (ft_line_search(pointer, &pointer));
}

/*
int	main(void)
{
	int fd = open("testfile.txt", O_RDONLY);
	char	*line;

	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
