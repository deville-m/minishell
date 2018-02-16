/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:10:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/16 15:43:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_string.h"

static char	**copyenv(void)
{
	char		**res;
	extern char	**environ;
	size_t		i;

	i = 0;
	while (environ[i])
		++i;
	if (!(res = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (environ[i])
	{
		res[i] = ft_strdup(environ[i]);
		++i;
	}
	res[i] = NULL;
	return (res);
}

int			main(int argc, char **argv)
{
	int			eof;
	char		*line;
	extern char	**g_env;

	(void)argc;
	g_env = copyenv();
	while (42)
	{
		prompt(g_env);
		signal(SIGINT, signal_handler);
		eof = !get_next_line(0, &line);
		if (!(g_env = process_input(line, argv, g_env)))
		{
			free(line);
			break ;
		}
		free(line);
		if (eof)
			break ;
	}
	deltab(g_env);
	return (0);
}
