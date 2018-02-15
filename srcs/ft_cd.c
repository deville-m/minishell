/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:17:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 17:16:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "minishell.h"
#include "ft_printf.h"

static void		update_pwd(char *olddir)
{
	char *curr;

	curr = getcwd(NULL, 0);
	if (!curr
		|| !olddir
		|| ft_setenv("OLDPWD", olddir, 1)
		|| ft_setenv("PWD", curr, 1))
		ft_fprintf(2, "cd: cannot update env\n");
	free(curr);
}

void			ft_cd(char *directory)
{
	struct stat	tmp;
	char		*olddir;

	if (!directory)
		directory = ft_getenv("HOME");
	else if (*directory == '-')
		directory = ft_getenv("OLDPWD");
	if (!directory || access(directory, F_OK))
		ft_printf("cd: no such file or directory: %s\n", directory);
	else if (stat(directory, &tmp) || !S_ISDIR(tmp.st_mode))
		ft_printf("cd: not a directory: %s\n", directory);
	else if (!(tmp.st_mode & S_IXUSR))
		ft_printf("cd: permission denied: %s\n", directory);
	else
	{
		olddir = getcwd(NULL, 0);
		if (chdir(directory))
			ft_fprintf(2, "cd: cannot change directory: %s\n", directory);
		update_pwd(olddir);
		free(olddir);
	}
}
