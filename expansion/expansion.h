/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 05:53:15 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/16 11:11:35 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "../minishell.h"

void	ft_expasion(t_list **tokens, int *last_status);
void	ft_quote_state(t_list *lst);
void	ft_expand(t_token *token, int *last_status);
void	ft_remove_quotes(t_token *token);

#endif