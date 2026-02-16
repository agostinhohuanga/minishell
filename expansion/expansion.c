/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 06:25:59 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/16 11:11:56 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	ft_expasion(t_list **tokens, int *last_status)
{
	t_token	*token;
	t_list	*lst_token;

	if (!*tokens)
		return ;
	lst_token = *tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		ft_expand(token, last_status);
		ft_remove_quotes(token);
		lst_token = lst_token->next;
	}
}
