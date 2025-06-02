/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:19:51 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 21:02:45 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_copy(char **matrice, char **copy)
{
	int	x;

	x = 0;
	copy = malloc(sizeof(char *) * (ft_line(matrice) + 1));
	if (!copy)
		return (NULL);
	while (x < ft_line(matrice))
	{
		copy[x] = ft_strdup(matrice[x]);
		if (!copy[x])
		{
			while (--x >= 0)
			{
				free(copy[x]);
				copy[x] = NULL;
			}
			free(copy);
			copy = NULL;
			return (NULL);
		}
		x++;
	}
	copy[ft_line(matrice)] = NULL;
	return (copy);
}

int	ft_line(char **matrice)
{
	int	line;

	line = 0;
	while (matrice[line])
		line++;
	return (line);
}

int	ft_bytes(char **matrice)
{
	int	bytes;

	bytes = 0;
	while (matrice[0][bytes])
		bytes++;
	return (bytes);
}

int	ft_is_element(char *line)
{
	int		i;
	int		j;
	char	*elements;

	i = 0;
	j = 0;
	elements = "01CEP";
	while (line[i])
	{
		while (line[i] != elements[j] && elements[j])
			j++;
		if (elements[j] == '\0')
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

void	ft_count_element(char **matrice, int *c, int *e, int *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*c = 0;
	*e = 0;
	*p = 0;
	while (matrice[i])
	{
		while (matrice[i][j])
		{
			if (matrice[i][j] == 'C')
				*c = *c + 1;
			if (matrice[i][j] == 'E')
				*e = *e + 1;
			if (matrice[i][j] == 'P')
				*p = *p + 1;
			j++;
		}
		j = 0;
		i++;
	}
}
