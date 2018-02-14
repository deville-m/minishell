/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:39:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 15:14:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "memory.h"
#include "ft_string.h"

static char	**new_slot(
				char **environ,
				const char *envname,
				const char *enval)
{
	char		**newenv;
	size_t		i;

	i = 0;
	while (environ[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	newenv[i + 1] = NULL;
	ft_memcpy(newenv, environ, sizeof(char *) * i);
	if (!(newenv[i] = ft_strnjoin(3, envname, "=", enval)))
	{
		deltab(newenv);
		return (NULL);
	}
	return (newenv);
}

char		**ft_setenv(
				char **environ,
				const char *envname,
				const char *enval,
				int overwrite)
{
	char		**slot;
	size_t		envsize[2];

	if (!environ)
		return (environ);
	if (ft_strchr(envname, '='))
		return (environ);
	envsize[0] = ft_strlen(envname);
	envsize[1] = ft_strlen(enval);;
	if (!(slot = findenv(environ, envname)))
	{
		environ = new_slot(environ, envname, enval);
		return (environ);
	}
	if (!overwrite)
		return (environ);
	if (ft_strlen(*slot) >= envsize[0] + envsize[1] + 1)
	{
		ft_strcpy(*slot + envsize[0] + 1, enval);
		return (environ);
	}
	free(*slot);
	*slot = ft_strnjoin(3, envname, "=", enval);
	return (environ);
}
