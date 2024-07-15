/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:33:42 by akrid             #+#    #+#             */
/*   Updated: 2024/07/15 13:47:31 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (new == NULL)
	{
		perror("malloc1");
		exit(1);
	}
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
