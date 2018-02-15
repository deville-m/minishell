/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:39:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:31:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "memory.h"
#include "ft_string.h"

static int	new_env(char ***environ, const char *name, const char *val)
{
	char		**newenv;
	size_t		i;

	i = 0;
	while ((*environ)[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * (i + 2))))
		return (-1);
	newenv[i + 1] = NULL;
	ft_memcpy(newenv, *environ, sizeof(char *) * i);
	if (!(newenv[i] = ft_strnjoin(3, name, "=", val)))
	{
		deltab(newenv);
		return (-1);
	}
	*environ = newenv;
	return (0);
}

int			ft_setenv(const char *name, const char *val, int overwrite)
{
	extern t_shell	sh;
	char			*slot;
	size_t			namesize;
	int				offset;

	if (!sh.env || !name || ft_strchr(name, '='))
		return (-1);
	if (!(slot = findenv(name, &offset)))
		return (new_env(&sh.env, name, val));
	if (!val)
	{
		slot[ft_strlen(name) + 1] = '\0';
		return (0);
	}
	namesize = ft_strlen(name);
	if (ft_strlen(slot) >= namesize + ft_strlen(val) + 1)
	{
		ft_strcpy(slot + namesize + 1, val);
		return (0);
	}
	free(slot);
	if (!(sh.env[offset] = ft_strnjoin(3, name, "=", val)))
		return (-1);
	else
		return (0);
}
