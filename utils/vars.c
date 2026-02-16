/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:18:17 by ahuanga           #+#    #+#             */
/*   Updated: 2026/02/16 11:00:05 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vars	*ft_vars_update(char **env)
{
	t_vars	*vars;
	int		size;
	int		i;

	if (!*env || !env)
		return (NULL);
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (NULL);
	i = -1;
	while (env[++i])
		ft_lstadd_back(&vars->lst_vars, ft_lstnew((void *)ft_strdup(env[i])));
	vars->ar_vars = ft_calloc((i + 1), sizeof(char *));
	i = -1;
	while (env[++i])
	{
		size = ft_strlen(env[i]);
		vars->ar_vars[i] = ft_calloc(size + 1, sizeof(char));
		if (!vars->ar_vars[i])
			return (NULL);
		ft_strlcpy(vars->ar_vars[i], env[i], size + 1);
	}
	return (vars);
}
