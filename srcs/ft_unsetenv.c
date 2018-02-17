/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:31 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 17:59:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char	**ft_unsetenv(char **env, const char *envname)
{
	char	**newenv;
	char	**slot;
	size_t	i;
	size_t	j;

	if (!(slot = findenv(env, envname)))
		return (env);
	i = 0;
	while (env[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * i)))
		return (env);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i] != *slot)
			newenv[j++] = env[i];
		++i;
	}
	newenv[j] = NULL;
	free(*slot);
	free(env);
	return (newenv);
}
