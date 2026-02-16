/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:11:07 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/16 11:12:26 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static char	*update_token(char *token, char *content, int *i, int var_length);
static char	*ft_token_expend(char *token, char *var_name, int pos, int *i);
static char	*get_var_name(char *token);
static char	*get_last_status(char *token, int *last_status, int *i);

void	ft_expand(t_token *token, int *last_status)
{
	int		i;
	int		quote[2];

	if (!token)
		return ;
	i = -1;
	quote[0] = 0;
	quote[1] = 0;
	while (token->value[++i])
	{
		if (token->value[i] == (char)39 && !quote[1])
			quote[0] = !quote[0];
		else if (token->value[i] == (char)34 && !quote[0])
			quote[1] = !quote[1];
		if (token->value[i] == '$' && !quote[0])
		{
			if (token->value[i + 1] == '?')
				token->value = get_last_status(token->value, last_status, &i);
			else
				token->value = ft_token_expend(token->value,
						get_var_name(token->value + i), i, &i);
			if (!token->value)
				return ;
		}
	}
}

static char	*update_token(char *token, char *content, int *i, int var_length)
{
	char	*new_token;
	int		length[3];
	int		pos;

	length[0] = ft_strlen(token);
	length[1] = ft_strlen(content);
	length[2] = (length[0] - (var_length + 1) + length[1] + 1);
	new_token = ft_calloc(length[2], 1);
	if (!new_token)
		return (free(token), free(content), NULL);
	pos = *i;
	ft_memcpy(new_token, token, pos);
	ft_memcpy(new_token + pos, content, (length[1]));
	*i = pos + length[1] - 1;
	ft_strlcpy(new_token + (*i + 1), token
		+ (pos + 1 + var_length), (length[2]));
	free(token);
	return (new_token);
}

static char	*ft_token_expend(char *token, char *var_name, int pos, int *i)
{
	char	*value;

	if (!var_name)
		return (token);
	pos++;
	value = getenv(var_name);
	if (!value)
		value = "";
	token = update_token(token, value, i, ft_strlen(var_name));
	return (free(var_name), token);
}

static char	*get_var_name(char *token)
{
	char	*name;
	int		i;

	i = 1;
	while (token[i] && (ft_isalnum(token[i]) || token[i] == '_'))
		i++;
	if (i == 1)
		return (NULL);
	name = ft_calloc(i, sizeof(char));
	if (!name)
		return (NULL);
	ft_strlcpy(name, token + 1, i);
	return (name);
}

static char	*get_last_status(char *token, int *last_status, int *i)
{
	char	*status;

	status = ft_itoa(*last_status);
	token = update_token(token, status, i, 1);
	free(status);
	return (token);
}
