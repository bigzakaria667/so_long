/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 19:28:29 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_shape(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i + 1])
	{
		if (ft_strlen(matrice[i]) != ft_strlen(matrice[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	read_file(char *s, char *stockage, int bytes)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read(fd, stockage, bytes) == -1)
		return (1);
	stockage[bytes] = '\0';
	return (close(fd), 0);
}

int	count_bytes(char *s)
{
	char	c;
	int		fd;
	int		bytes_read;
	int		count;

	if (!s)
		return (1);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	count = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read > 0)
			count++;
	}
	return (close(fd), count);
}

char	**check_map(char *s)
{
	char	*stockage;
	char	**matrice;
	int		bytes;

	stockage = NULL;
	matrice = NULL;
	bytes = count_bytes(s);
	if (bytes <= 0)
		return (NULL);
	stockage = malloc(sizeof(char) * bytes + 1);
	if (!stockage)
		return (NULL);
	if (read_file(s, stockage, bytes))
		return (free(stockage), NULL);
	matrice = ft_split(stockage, '\n');
	if (!matrice || check_shape(matrice) || check_data(matrice))
		return (free(stockage), free_matrice(&matrice), NULL);
	return (free(stockage), matrice);
}
