/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:10:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 14:52:00 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_string.h"

static char **copyenv()
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

int	main(int argc, char **argv)
{
	char		*line;
	char		**env;

	(void)argc;
	env = copyenv();
	while (42)
	{
		prompt();
		get_next_line(0, &line);
		if ((ft_strnequ(line, "exit", 4) && (!line[4] || line[4] == ' '))
			|| !(env = process_input(line, argv, env)))
		{
			free(line);
			break ;
		}
		free(line);
	}
	deltab(env);
	return (0);
}
