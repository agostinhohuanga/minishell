/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:36:02 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/16 10:57:24 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	ft_remove_quotes(t_token *token)
{
	char	*str;
	char	quote;
	int		i;
	int		e;

	if (!token->value)
		return ;
	str = token->value;
	i = 0;
	e = -1;
	quote = 0;
	while (str[++e])
	{
		if ((str[e] == (char)34 || str[e] == (char)39) && !quote)
			quote = str[e];
		else if (str[e] == quote)
			quote = 0;
		else
			str[i++] = str[e];
	}
	str[i] = '\0';
}
