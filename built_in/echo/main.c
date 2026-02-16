/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuanga <marvin@42fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:17:31 by ahuanga           #+#    #+#             */
/*   Updated: 2026/01/23 14:48:51 by ahuanga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static int	search_arg(const char *src, const char *word);

int	main(int argc, char **argv)
{
	int	i;
	int	newline;

	newline = 1;
	if (argc > 1)
	{
		i = 1;
		while (search_arg(argv[i++], "-n"))
			newline = 0;
		i--;
		while (argv[i])
		{
			printf("%s", argv[i]);
			if (argv[i + 1])
				printf(" ");
			i++;
		}
	}
	if (newline)
		printf("\n");
	return (0);
}

static int	search_arg(const char *src, const char *arg)
{
	int	i;

	if (!src || !arg)
		return (0);
	i = 0;
	while (src[i] && arg[i] && src[i] == arg[i])
	{
		if (!arg[i + 1] && !src[i + 1])
			return (1);
		i++;
	}
	return (0);
}
