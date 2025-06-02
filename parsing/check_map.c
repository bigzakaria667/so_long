/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/31 21:41:39 by zel-ghab         ###   ########.fr       */
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

	// OUVRIR LE FICHIER
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	// EXTRAIRE LA MAP
	if (read(fd, stockage, bytes) == -1)
		return (1);
	stockage[bytes] = '\0';
	return (close(fd), 0);
}

int	count_bytes(char *s)
{
	int	fd;
	int	bytes_read;
	int	count;
	char	c;

	count = 0;
	// OUVRIR LE FICHIER
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	// EXTRAIRE LA MAP
	while ((bytes_read = read(fd, &c, 1)) > 0)
		count++;
	return (close(fd), count);
}

char	**check_map(char *s)
{
	char	*stockage;
	char	**matrice;

	matrice = NULL;
	stockage = malloc(sizeof(char) * count_bytes(s) + 1);
	if (!stockage)
		return (NULL);
	if (read_file(s, stockage, count_bytes(s)))
		return (free(stockage), NULL);
	//matrice = set_matrice(stockage);
	matrice = ft_split(stockage, '\n');
	if (!matrice || check_shape(matrice) || check_data(matrice))
		return (free(stockage), free_matrice(&matrice), NULL);
	return (free(stockage), matrice);
}
