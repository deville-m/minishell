/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:31 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:30:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int		ft_unsetenv(const char *name)
{
	extern t_shell	sh;
	char			**newenv;
	char			*slot;
	int				i;
	int				j;

	if (!name || !(slot = findenv(name, &j)))
		return (0);
	i = 0;
	while (sh.env[i])
		++i;
	if (!(newenv = (char **)malloc(sizeof(char *) * i)))
		return (-1);
	i = -1;
	j = 0;
	while (sh.env[++i])
	{
		if (sh.env[i] == slot)
			newenv[j++] = sh.env[i];
	}
	newenv[i] = NULL;
	free(sh.env);
	free(slot);
	sh.env = newenv;
	return (0);
}
