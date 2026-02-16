/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:37:47 by ckulembe          #+#    #+#             */
/*   Updated: 2025/08/03 01:48:48 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*node;

	count = 0;
	if (!lst)
		return (count);
	else
	{
		while (lst)
		{
			count++;
			node = lst->next;
			lst = node;
			node = NULL;
		}
	}
	return (count);
}
