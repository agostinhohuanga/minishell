/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckulembe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:19:57 by ckulembe          #+#    #+#             */
/*   Updated: 2026/02/03 13:31:26 by ckulembe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "../minishell.h"

int		ft_is_space(char c);
int		ft_is_operator(const char *line, int i);
int		ft_is_quote(char c);

void	ft_tokenclear(void *arg);
void	ft_get_token_type(void *arg);

t_data	ft_data(int start, int *i, int *n);
t_list	*ft_tokenize(const char *line);

#endif
