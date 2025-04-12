/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/12 16:48:45 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	put_into_matrice(char *stockage, char ***matrice)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	j = 0;
	s = 0;
	while (stockage[s])
	{
		while (stockage[s] != '\n')
			matrice[i][j++] = stockage[s++];
		i++;
	}
}

int	bytes_counter(char *stockage)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	while (stockage[i])
	{
		if (stockage[i] == '\n')
			return (bytes);
		bytes++;
		i++;
	}
	return (0);
}

int	line_counter(char *stockage)
{
	int	line;

	line = 0;
	while (stockage[i])
	{
		if (stockage[i] == '\n')
			line++;
		
		i++;
	}
	return (line);
}

int	set_matrice(char *stockage. char ***matrice)
{
	int	i;
	int	line;
	int	bytes;

	i = 0;
	line = line_counter(stockage);
	bytes =  bytes_counter(stockage);
	if (line < 3 || bytes < 3)
		return (1);
	matrice = malloc (sizeof(char *) * (line + 1));
	if (!matrice)
		return (1);
	while (matrice != NULL)
	{
		matrice[i] = malloc (sizeof(char) * bytes + 1);
		if (!matrice[i])
			return (1);
		i++;
	}
	put_into_matrice(stockage, matrice);
	return (0);
}
