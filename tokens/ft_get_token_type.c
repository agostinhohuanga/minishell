/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:50:29 by ckulembe          #+#    #+#             */
/*   Updated: 2026/01/29 11:39:58 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static t_token_type	ft_type(char *operator, size_t length);

void	ft_get_token_type(void *arg)
{
	size_t	length;
	t_token	*token;

	if (!arg)
		return ;
	token = (t_token *) arg;
	length = ft_strlen(token->value);
	token->type = ft_type(token->value, length);
	return ;
}

static t_token_type	ft_type(char *operator, size_t length)
{
	t_token_type	type;

	type = WORD;
	if (length == 1)
	{
		if (!ft_strncmp(operator, "<", length))
			type = REDIR_IN;
		else if (!ft_strncmp(operator, ">", length))
			type = REDIR_OUT;
		else if (!ft_strncmp(operator, "|", length))
			type = PIPE;
	}
	else if (length == 2)
	{
		if (!ft_strncmp(operator, "<<", length))
			type = HEREDOC;
		else if (!ft_strncmp(operator, ">>", length))
			type = REDIR_APPEND;
	}
	return (type);
}
