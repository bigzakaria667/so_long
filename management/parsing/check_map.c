/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/12 17:06:20 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	read_file(char **stockage)
{
	int	fd;
	int	bytes_read;

	// OUVRIR LE FICHIER
	fd = open(stockage, O_RDONLY);
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

int	check_map(char *s)
{
	char	stockage[8000];
	char	**matrice;

	if (read_file(&stockage) == 1)
		return (1);
	if (set_matrice(stockage, &matrice) == 1)
		return (1);
	printf("%s", stockage);
	return (0);
}
