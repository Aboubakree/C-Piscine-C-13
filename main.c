/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:13:35 by akrid             #+#    #+#             */
/*   Updated: 2024/08/27 10:07:55 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int compair(void *x1, void *x2)
{
	if (*((int *)x1) > *((int *)x2))
		return (1);
	if (*((int *)x1) < *((int *)x2))
		return (-1);
	return (0);
}

void applyf(void *item)
{
	printf("%d ", *((int *)item));
}

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
	// print tree using prefix traversel !!?
	if (root == NULL)
		return ;
	printf("node : %d\nvalue : %d\n", *index, *((int *)root->item));
	(*index) ++;
	print_tree(root->left, index);
	print_tree(root->right, index);
}

void	free_tree(t_btree *root)
{
	if (root && root->left)
		free_tree(root->left);
	if (root && root->right)
		free_tree(root->right);
	if (root && root->item)
		free(root->item);
	if (root)
		free(root);
}

int main()
{
	t_btree	*root;
	int		index;

	root = NULL;
	index = 0;
	// create_tree(&root, 3);
	// print_tree(root, &index);
	// btree_apply_prefix(root, applyf);
	// printf("\n+++++++++++++++++++++++++++\n");
	// btree_apply_infix(root, applyf);
	// printf("\n+++++++++++++++++++++++++++\n");
	// btree_apply_suffix(root, applyf);
	// printf("\n+++++++++++++++++++++++++++\n");
	btree_insert_data(&root, generate_random_int(), compair);
	btree_insert_data(&root, generate_random_int(), compair);
	btree_insert_data(&root, generate_random_int(), compair);
	btree_insert_data(&root, generate_random_int(), compair);
	index = 0;
	print_tree(root, &index);
	free_tree(root);
}