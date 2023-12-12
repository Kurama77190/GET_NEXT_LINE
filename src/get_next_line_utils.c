/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:42:40 by sben-tay          #+#    #+#             */
/*   Updated: 2023/12/12 05:41:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*trouver le retour a la ligne.
[\fonction_personaliser_booléenne/]*/

int	trouve_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	i = 0;
	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*Return le pointeur du dernier noeux de ma liste.
 [\cette fonction sera ajoutée à ma libft/]*/

t_list	*ft_lst_get_last(t_list *link_ptr)
{
	t_list	*current;

	current = link_ptr;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}
