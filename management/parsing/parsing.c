/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/12 17:00:05 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_extension(char *s)
{
	int	i;
	int	j;
	int	len;
	char	*ber;
	
	len = ft_strlen(s);
	if (len < 5)
		return (1);
	ber = ".ber";
	i = len - 4;
	j = 0;
	while (s[i] == ber[j] && s[i]) 
	{
		i++;
		j++;
	}
	if (s[i] != '\0')
		return (1);
	return (0);
}

void	instructions(char **argv)
{
	if (check_extension(argv[1]) == 1)
		ft_error("⚠️ Le fichier n'a pas l'extension .ber\n");
	if (check_map(argv[1]))
		ft_error("⚠️ La map n'est pas valide\n");
}
