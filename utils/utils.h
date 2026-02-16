/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:29:24 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/10 18:59:36 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

void	ft_historic(void *line);
void	handler(int sig);
void	windown_update(t_list *tokens);
t_vars	*ft_vars_update(char **env);
void	lst_free(void *content);

#endif