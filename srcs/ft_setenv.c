/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:39:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 20:11:06 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "memory.h"
#include "ft_string.h"

int		replace_slot(
					char **slot,
					const char *envname,
					const char *enval,
					size_t envsize[])
{
	if (!(*slot = (char *)malloc(sizeof(char) * (envsize[0] + envsize[1] + 2))))
		return (-1);
	ft_strcpy(*slot, envname);
	(*slot)[envsize[0]] = '=';
	ft_strcpy(*slot + envsize[0] + 1, enval);
	return (0);
}

int		new_slot(
				char **environ,
				const char *envname,
				const char *enval,
				size_t envsize[])
{
	char		**newenv;
	size_t		i;

	i = 0;
	while (environ[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * (++i + 1))))
		return (-1);
	newenv[i] = NULL;
	ft_memcpy(newenv, environ, sizeof(char *) * i);
	if (replace_slot(newenv + i, envname, enval, envsize) == -1)
		return (-1);
	free(environ);
	environ = newenv;
	return (0);
}

int		ft_setenv(const char *envname, const char *enval, int overwrite)
{
	extern char	**environ;
	char		**slot;
	size_t		envsize[2];

	if (ft_strchr(envname, '='))
		return (-1);
	envsize[0] = ft_strlen(envname);
	envsize[1] = ft_strlen(enval);;
	if (!(slot = findenv(environ, envname)))
		return (new_slot(environ, envname, enval, envsize));
	if (!overwrite)
		return (0);
	if (ft_strlen(*slot) >= envsize[0] + envsize[1] + 1)
	{
		ft_strcpy(*slot + envsize[0] + 1, enval);
		return (0);
	}
	free(*slot);
	return (replace_slot(slot, envname, enval, envsize));
}
