/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:26:56 by ahuanga           #+#    #+#             */
/*   Updated: 2026/01/21 08:29:25 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_historic(void *line)
{
	if (!line)
	{
		rl_clear_history();
		printf("exit\n");
		exit(1);
	}
	if (ft_isprint(((char *)line)[0]))
		add_history(line);
	rl_redisplay();
}
