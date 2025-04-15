/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/14 22:27:26 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**put_into_matrice(char *stockage, char **matrice)
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
		matrice[i][j] = '\0';
		j = 0;
		i++;
		s++;
	}
	return (matrice);
}

int	bytes_counter(char *stockage)
{
	int	i;

	i = 0;
	while (stockage[i] != '\n')
		i++;
	return (i);
}

int	line_counter(char *stockage)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (stockage[i])
	{
		if (stockage[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

char	**set_matrice(char *stockage)
{
	int	i;
	int	line;
	int	bytes;
	char	**matrice;

	line = line_counter(stockage);
	bytes =  bytes_counter(stockage);
	if (line < 3 || bytes < 3)
		return (NULL);
	matrice = malloc (sizeof(char *) * (line + 1));
	if (!matrice)
		return (NULL);
	i = 0;
	while (i < line)
	{
		matrice[i] = malloc (sizeof(char) * bytes + 1);
		if (!matrice[i])
			return (NULL);
		i++;
	}
	matrice[line] = NULL;
	put_into_matrice(stockage, matrice);
	return (matrice);
}
