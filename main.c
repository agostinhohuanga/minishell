/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:42 by ckulembe          #+#    #+#             */
/*   Updated: 2026/02/16 11:24:06 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenprint(void *arg)
{
	t_token	*token;

	if (!arg)
		return ;
	token = (t_token *)arg;
	// printf("%s\t%d\t%d\n", token->value, token->type, token->quote_state);
	printf("%s", token->value);
	return ;
}
void	ft_varprint(void *var)
{
	if (!var)
		return ;
	printf("%s\n", (char *)var);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*tokens;
	t_vars	*env_vars;
	// int		i;
	char	*message;

	signal(2, handler);
	signal(3, SIG_IGN);
	env_vars = ft_vars_update(env);
	// i = -1;
	// while (env_vars->ar_vars[++i])
	// 	printf("%s\n", env_vars->ar_vars[i]);
	env_vars->last_status = 0;
	while (1)
	{
		message = readline("minishell$ ");
		ft_historic(message);
		tokens = ft_tokenize(message);
		windown_update(tokens);
		// printf("Value\tType\tQuotes\n");
		// printf("======================\n");
		ft_expasion(&tokens, &env_vars->last_status);
		ft_lstiter(tokens, ft_tokenprint);
		printf("\n");
		ft_lstclear(&tokens, ft_tokenclear);
		free(message);
	}
	ft_lstclear(&env_vars->lst_vars, lst_free);
	(void)argv;
	(void)argc;
	return (0);
}
