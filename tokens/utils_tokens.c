/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:17:07 by ckulembe          #+#    #+#             */
/*   Updated: 2026/01/29 09:22:33 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

int	ft_is_space(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_is_operator(const char *line, int i)
{
	if (line[i] == 124)
		return (1);
	else if (line[i] == 60)
		return (1);
	else if (line[i] == 62)
		return (1);
	return (0);
}

int	ft_is_quote(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

t_data	ft_data(int start, int *i, int *n)
{
	t_data	data;

	if (!i || !n)
	{
		data.i = 0;
		data.n = 0;
	}
	data.i = i;
	data.n = n;
	data.start = start;
	return (data);
}

void	ft_tokenclear(void *arg)
{
	t_token	*token;

	if (!arg)
		return ;
	token = (t_token *)arg;
	if (token->value)
		free(token->value);
	free(token);
	return ;
}
