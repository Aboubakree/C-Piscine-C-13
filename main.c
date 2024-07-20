/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:13:35 by akrid             #+#    #+#             */
/*   Updated: 2024/07/20 13:26:49 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	*generate_random_int()
{
	int	*nbr = malloc(sizeof(int));

	if (nbr == NULL)
	{
		perror("malloc1");
		exit(1);
	}
	*nbr = rand() % 100;
	return (nbr);
}

void	create_tree(t_btree **root, int lvl)
{
	t_btree	*new;

	if (lvl <= 0)
		return ;
	new = NULL;
	if (*root == NULL)
		new  = btree_create_node(generate_random_int());
	create_tree(&new->left, lvl - 1);
	create_tree(&new->right, lvl - 1);
	*root = new;
	return ;
}

void	print_tree(t_btree *root, int *index)
{
	if (root == NULL)
		return ;
	printf("node : %d\nvalue : %d\n", *index, *((int *)root->item));
	(*index) ++;
	print_tree(root->left, index);
	print_tree(root->right, index);
}

void	free_tree(t_btree)
{
	
}

int main()
{
	t_btree	*root;
	int		index;

	root = NULL;
	index = 0;
	create_tree(&root, 4);
	print_tree(root, &index);
}