/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:49:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/16 15:08:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "ft_string.h"
#include "ft_printf.h"

static int	is_exit(char *input, char **env)
{
	if (!input)
		return (0);
	while (*input == ' ')
		input++;
	if (ft_strnequ(input, "exit", 4) && (!input[4] || input[4] == ' '))
	{
		deltab(env);
		return (1);
	}
	else
		return (0);
}

char		**process_input(char *input, char **av, char **env)
{
	extern int	g_pid;
	char		**split;
	char		*bin_path;

	if (is_exit(input, env))
		return (NULL);
	if (!(split = ft_strsplit(input, ' ')) || !split[0])
		return (env);
	if (is_builtin(split, &env))
		return (env);
	if (!(bin_path = getpath(split[0], env)))
		ft_fprintf(2, "%s: command not found: %s\n", av[0], split[0]);
	else if (access(bin_path, X_OK) == -1)
		ft_fprintf(2, "%s: permission denied: %s\n", av[0], split[0]);
	else if ((g_pid = fork()) == -1)
		ft_fprintf(2, "Could not fork\n");
	else
	{
		(signal(SIGINT, proc_signal_handler) != SIG_ERR && !g_pid) ?
			execve(bin_path, split, env) :
			wait(&g_pid);
	}
	deltab(split);
	free(bin_path);
	return (env);
}
