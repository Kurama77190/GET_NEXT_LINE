/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:23:59 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/15 14:23:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*inventaire;
	char			*ligne;
	size_t			compteur;

	inventaire = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0 || fd > 1024)
		return (NULL);
	compteur = 1;
	ligne = NULL;
	// 1. Lire fd et copier dans la list
	lire_et_inventaire(fd, &inventaire, &compteur);
	if (inventaire == NULL)
		return (NULL);
	// 2. extraire l'inventaire dans ligne
	extraire_inventaire(inventaire, &ligne);
	// 3. netoyez l iventaire
	clean_inventaire(&inventaire);
	if (ligne[0] == '\0')
	{
		free_inventaire(inventaire);
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

/*utiliser read() pour ajouter les caracteres dans mon inventaire*/

void	lire_et_inventaire(int fd, t_list **inventaire, int *compteur)
{
	char	*buf;

	while (!trouve_newline(*inventaire) && *compteur != 0)
	{
		buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		*compteur = read(fd, buf, BUFFER_SIZE);
		if ((*inventaire == NULL && compteur == 0) || *compteur == -1)
		{
			free(buf);
			return ;
		}
		buf[*compteur] = '\0';
		transfert_inventaire(inventaire, buf, *compteur);
		free(buf);
	}
}

/*Ajoute le contenue de mon buffer a la fin de mon inventaire*/

void	transfert_inventaire(t_list **inventaire, char *buf, size_t compteur)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char *) * (compteur + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < compteur)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*inventaire == NULL)
	{
		*inventaire = new_node;
		return ;
	}
	last = ft_lst_get_last(*inventaire);
	last->next = new_node;
}


/*extraire la ligne de l inventaire dans ligne et liberer 
la memoire des noeuds copier*/

void	extraire_inventaire(t_list *inventaire, char **ligne)
{
	int	i;
	int	j;

	if (inventaire == NULL)
		return ;

	generer_ligne(ligne, inventaire);
	if (*ligne == NULL)
		return ;
	while (inventaire)
	{
		i = 0;
		while (inventaire->content[i])
		{
			if (inventaire ->content[i] == '\n')
			{
				(*ligne)[j++] = inventaire->content[i];
				break ;
			}
			(*ligne)[j++] = inventaire->content[i++];
		}
		inventaire = inventaire->next;
	}
	(*ligne)[j] = '\0';
}

void	clean_inventaire(t_list **inventaire)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (inventaire == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*inventaire);
	i = 0;
	while (last ->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * \
	((ft_strlen(last->content - i) + 1)));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_inventaire(*inventaire);
	*inventaire = clean_node;
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
