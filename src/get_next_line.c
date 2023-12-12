/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:23:59 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/12 04:28:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd);
{
	static t_list	*inventaire;
	char			*ligne;
	size_t			compteur;

	*inventaire = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0 || fd > 1024)
		return (NULL);
	compteur = 1;
	ligne = NULL;
	// 1. Lire fd et copier dans la list
	lire_et_inventaire(fd, &inventaire, &compteur)
	if (inventaire == NULL)
		return (NULL);
	// 2. extraire l'inventaire dans ligne
	// 3. netoyez l iventaire
	return (line);
}

/*utiliser read() pour ajouter les caracteres dans mon inventaire*/

void	lire_et_inventaire(int fd, t_list **inventaire, int *compteur)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return ;
	while (!trouve_newline(*inventaire) && *compteur != 0)
	{
		*compteur = read(fd, buf, BUFFER_SIZE);
		if ((*inventaire == NULL && compteur == 0) || *compteur == -1)
		{
			free(buf);
			return ;
		}
		buf[*compteur] = '\0';
	}
}

















// # include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test/simple", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
