/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:32:14 by akrid             #+#    #+#             */
/*   Updated: 2024/08/26 11:28:32 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <error.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;


/* FUNCTIONS */
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
;
void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
;
void btree_apply_infix(t_btree *root, void (*applyf)(void *))
;
t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

#endif