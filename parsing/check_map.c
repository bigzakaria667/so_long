/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/17 17:06:20 by zel-ghab         ###   ########.fr       */
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

int	read_file(char *s, char *stockage)
{
	int	fd;
	int	bytes_read;

	// OUVRIR LE FICHIER
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	// EXTRAIRE LA MAP
	bytes_read = read(fd, stockage, 1024);
	if (bytes_read < 0)
		return (1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, stockage, 1024);
		if (bytes_read < 0)
			return (1);
	}
	return (0);
}

char	**check_map(char *s)
{
	char	stockage[8000];
	char	**matrice;

	matrice = NULL;
	if (read_file(s, stockage) == 1)
		return (NULL);
	matrice = set_matrice(stockage);
	if (matrice == NULL)
		return (NULL);
	if (check_shape(matrice) == 1)
		return (NULL);
	if (check_data(matrice) == 1)
		return (NULL);
	return (matrice);
}
