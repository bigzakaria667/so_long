/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 19:41:44 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *s)
{
	char	*ber;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s);
	if (len < 5)
		return (1);
	ber = ".ber";
	i = len - 4;
	j = 0;
	while ((s[i] == ber[j]) && s[i])
	{
		i++;
		j++;
	}
	if (s[i] != '\0')
		return (1);
	return (0);
}

char	**parsing(char **argv)
{
	char	**matrice;

	if (check_extension(argv[1]) == 1)
		ft_error("⚠️ Le fichier n'a pas l'extension .ber\n");
	matrice = check_map(argv[1]);
	if (matrice == NULL)
		return (free_matrice(&matrice), \
			ft_error("⚠️ La map n'est pas valide\n"), NULL);
	if (check_playable(matrice) == 1)
		return (free_matrice(&matrice), \
			ft_error("⚠️ La map n'est pas jouable\n"), NULL);
	return (matrice);
}
