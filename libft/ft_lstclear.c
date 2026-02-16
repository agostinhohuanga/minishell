/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:20:02 by ckulembe          #+#    #+#             */
/*   Updated: 2025/08/03 01:50:22 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!(*lst) || !del)
		return ;
	else
	{
		while (*lst)
		{
			node = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = node;
		}
	}
	return ;
}
