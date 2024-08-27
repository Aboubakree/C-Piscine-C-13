/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:57:40 by akrid             #+#    #+#             */
/*   Updated: 2024/08/27 10:13:46 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root)
	{
		printf("root : %d\n", *((int *)(*root)->item));
		printf("item : %d\n", *((int *)item));
		printf("++++++++++++++++++++++++++++++++\n");
	}
	if (*root == NULL)
		*root = btree_create_node(item);
	else if ((*root)->left == NULL)
	{
		if (cmpf((*root)->item, item) < 0)
		{
			btree_insert_data(&(*root)->left, (*root)->item, cmpf);
			(*root)->item = item;
		}
		else
			btree_insert_data(&(*root)->left, item, cmpf);
	}
	else if ((*root)->right == NULL)
	{
		if (cmpf((*root)->item, item) < 0)
		{
			btree_insert_data(&(*root)->right, (*root)->item, cmpf);
			(*root)->item = item;
		}
		else
			btree_insert_data(&(*root)->right, item, cmpf);
	}
}
