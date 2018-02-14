/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:17:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 18:19:40 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "minishell.h"
#include "ft_printf.h"

static char		**update_pwd(char *olddir, char **env)
{
	char *curr;

	curr = getcwd(NULL, 0);
	env = ft_setenv(env, "OLDPWD", olddir, 1);
	env = ft_setenv(env, "PWD", curr, 1);
	free(curr);
	return (env);
}

char			**ft_cd(char *directory, char **env)
{
	struct stat tmp;
	char		*olddir;

	if (!directory)
		directory = ft_getenv("HOME", env);
	else if (*directory == '-')
		directory = ft_getenv("OLDPWD", env);
	if (!directory || access(directory, F_OK))
		ft_printf("cd: no such file or directory: %s\n", directory);
	else if (stat(directory, &tmp) || !S_ISDIR(tmp.st_mode))
		ft_printf("cd: not a directory: %s\n", directory);
	else if (!(tmp.st_mode & S_IXUSR))
		ft_printf("cd: permission denied: %s\n", directory);
	else
	{
		olddir = getcwd(NULL, 0);
		chdir(directory);
		env = update_pwd(olddir, env);
		free(olddir);
	}
	return (env);
}
