/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:19:51 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/15 16:42:47 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int	i;
	int	j;
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
