/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:14:13 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/15 15:24:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

int		trouve_newline(t_list *stash);

void	lire_et_inventaire(int fd, t_list **inventaire, int *compteur);

t_list	*ft_lst_get_last(t_list *link_ptr);

void	transfert_inventaire(t_list	**inventaire, char *buf, size_t compteur);

void	clean_inventaire(t_list **inventaire);

int		ft_strlen(const char *str);

void	free_inventaire(t_list **inventaire);

void	generer_ligne(char **ligne, t_list *inventaire);

void	extraire_inventaire(t_list *inventaire, char **ligne);

#endif