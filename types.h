/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:28:12 by ckulembe          #+#    #+#             */
/*   Updated: 2026/02/16 11:08:45 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_data
{
	int	start;
	int	*n;
	int	*i;
}	t_data;

typedef enum s_token_type
{
	WORD,
	PIPE,
	HEREDOC,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND
}	t_token_type;

typedef enum s_quote_state
{
	NO_QUOTES,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
}	t_quote_state;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	t_quote_state	quote_state;
}	t_token;

typedef struct s_redir
{
	char			*value;
	t_token_type	type;
	struct s_redir	*next;
}	t_redir;

typedef struct s_command
{
	char	*action;
	char	**args;
	t_redir	*redir;
}	t_command;

typedef struct s_vars
{
	t_list	*lst_vars;
	char	**ar_vars;
	int		last_status;
}	t_vars;

#endif
