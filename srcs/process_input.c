/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:49:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 18:11:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "ft_string.h"
#include "ft_printf.h"


int		process_input(char *input, char **av)
{
	int			pid;
	extern char	**environ;
	char		**split;
	char		*bin_path;

	if (!(split = ft_strsplit(input, ' ')) || ft_strequ(split[0], "exit"))
		return (0);
	if (is_builtin(split))
		return (1);
	if (!(bin_path = getpath(split[0])))
		ft_fprintf(2, "%s: command not found: %s\n", av[0], split[0]);
	else if (access(bin_path, X_OK) == -1)
		ft_fprintf(2, "%s: permission denied: %s\n", av[0], split[0]);
	else if ((pid = fork()) == -1)
		ft_fprintf(2, "Could not fork\n");
	else
	{
		if (!pid)
			execve(bin_path, split, environ);
		wait(NULL);
	}
	deltab(split);
	free(bin_path);
	return (1);
}
