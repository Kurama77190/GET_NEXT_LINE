/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:23:59 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/12 02:54:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
{
	static t_list	*inventaire;
	char			*ligne;
	size_t			compteur;

	*inventaire = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &igne, 0) < 0)
		return (NULL);
	compteur = 1;
	ligne = NULL;
	// 1. Lire fd et copier dans la list
	// 2. extraire l'inventaire dans ligne
	// 3. netoyez l iventaire
	return (line);
}

/*utiliser read() pour ajouter les caracteres dans ma stash*/



















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