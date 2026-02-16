/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:47:47 by ckulembe          #+#    #+#             */
/*   Updated: 2026/01/29 11:38:22 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

static int	ft_extract_word_in(t_list **tokens, const char *line, t_data d);
static int	ft_extract_operator(t_list **tokens, const char *line, int *n);
static void	ft_extract_word(t_list **tokens, const char *line,
				int *n, int start);
static void	ft_add_token(t_list **tokens, const char *line,
				int start, int length);

t_list	*ft_tokenize(const char *line)
{
	int		i;
	t_list	*list;
	t_list	*tokens;

	tokens = ft_lstnew("init");
	if (!tokens)
		return (NULL);
	i = 0;
	while (*(line + i))
	{
		while (*(line + i) == 32)
			i++;
		if (!line[i])
			break ;
		if (ft_is_operator(line, i))
		{
			ft_extract_operator(&tokens, line, &i);
			continue ;
		}
		ft_extract_word(&tokens, line, &i, i);
	}
	list = tokens->next;
	return (free(tokens), list);
}

static int	ft_extract_operator(t_list **tokens, const char *line, int *n)
{
	int	oplen;

	oplen = 1;
	if (line[*n + 1] && (line[*n] == '<' || line[*n] == '>')
		&& line[*n] == line[*n + 1])
		oplen = 2;
	ft_add_token(tokens, line, *n, oplen);
	*n += oplen;
	return (1);
}

static int	ft_extract_word_in(t_list **tokens, const char *line, t_data d)
{
	char	*_addr;

	if (ft_is_quote(line[*(d.i)]))
	{
		_addr = ft_strchr((line + *(d.i) + 1), *(line + *(d.i)));
		if (!_addr)
		{
			*(d.n) = ft_strlen(line);
			ft_add_token(tokens, line, d.start, *d.i - d.start);
			return (1);
		}
		*(d.i) = _addr - line;
	}
	return (0);
}

static void	ft_extract_word(t_list **tokens,
			const char *line, int *n, int start)
{
	int	i;

	i = *n;
	while (*(line + i) && !ft_is_space(*(line + i)))
	{
		if (ft_is_operator(line, i))
		{
			ft_add_token(tokens, line, start, i - start);
			*n = i;
			return ;
		}
		if (ft_extract_word_in(tokens, line, ft_data(start, &i, n)))
			return ;
		if (!line[i + 1] && (ft_is_operator(line, i + 1)
				|| ft_is_space(line[i + 1])))
		{
			ft_add_token(tokens, line, start, i - start);
			*n = i + 1;
			break ;
		}
		i++;
	}
	if (i > start)
		ft_add_token(tokens, line, start, i - start);
	*n = i;
}

static void	ft_add_token(t_list **tokens, const char *line,
			int start, int length)
{
	t_token	*token;
	t_list	*node;

	token = (t_token *) malloc(sizeof(t_token));
	if (!token)
		return ;
	token->value = ft_substr(line, start, (size_t)length);
	if (!token->value)
	{
		free(token);
		return ;
	}
	ft_get_token_type(token);
	node = ft_lstnew(token);
	if (!node)
	{
		free(token->value);
		free(token);
		return ;
	}
	ft_lstadd_back(tokens, node);
}
