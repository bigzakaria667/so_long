/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:03:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/10 15:19:22 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_update_stock(char **stockage, int n)
{
	int		len;
	char	*updatestock;

	if (!stockage)
		return (NULL);
	len = gnl_strlen(*stockage);
	if (len > n + 1)
	{
		updatestock = gnl_substr(*stockage, n + 1, len);
		if (!updatestock)
			return (free(*stockage), *stockage = NULL, NULL);
	}
	else
		updatestock = NULL;
	return (free(*stockage), *stockage = NULL, updatestock);
}

static char	*ft_extract_line(char *stockage, int n)
{
	char	*line;

	line = gnl_substr(stockage, 0, n + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_finder(char **stockage, char **buffer, int bytes_read)
{
	int		i;
	char	*line;

	if (!*stockage)
		*stockage = gnl_strdup(*buffer, bytes_read);
	else
		*stockage = gnl_strjoin(*stockage, *buffer, bytes_read);
	if (!*stockage && *buffer)
		return (free(*buffer), NULL);
	else if (!*stockage)
		return (NULL);
	i = 0;
	while ((*stockage)[i] && (*stockage)[i] != '\n')
		i++;
	if ((*stockage)[i] == '\n')
	{
		line = ft_extract_line(*stockage, i);
		if (!line)
			return (free(*stockage), *stockage = NULL, NULL);
		*stockage = ft_update_stock(stockage, i);
		return (line);
	}
	return (NULL);
}

char	*ft_read(int fd, char **stockage, char **buffer, int *bytes_read)
{
	*buffer = malloc (sizeof(char) * BUFFER_SIZE);
	if (!*buffer)
		return (free(*stockage), *stockage = NULL, NULL);
	*bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
		return (free(*stockage), *stockage = NULL, free(*buffer),
			*buffer = NULL, NULL);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*stockage;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || (long)BUFFER_SIZE > (long)MAXINT
		|| read(fd, 0, 0) < 0)
		return (free(stockage), stockage = NULL, NULL);
	ft_read(fd, &stockage, &buffer, &bytes_read);
	if (!buffer)
		return (free(stockage), stockage = NULL, NULL);
	while (bytes_read != 0 || gnl_strchr(stockage, '\n'))
	{
		line = ft_finder(&stockage, &buffer, bytes_read);
		if (line != NULL)
			return (line);
		if (!gnl_strchr(stockage, '\n'))
			ft_read(fd, &stockage, &buffer, &bytes_read);
		if (!buffer)
			return (free(stockage), stockage = NULL, NULL);
	}
	if (stockage && gnl_strlen(stockage) > 0)
		return (line = stockage, stockage = NULL, free(buffer), line);
	return (free(stockage), stockage = NULL, free(buffer), NULL);
}
/*
int	main()
{
	char	*s;
	int	fd;

	fd = open("Coran.txt", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		printf("%s", s);
		free(s);
	}
}
*/
