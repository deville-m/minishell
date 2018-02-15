/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:28:02 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 17:42:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "ft_string.h"

int		init_shell(void)
{
	extern char		**environ;
	extern t_shell	sh;
	size_t			i;

	while (environ[i])
		++i;
	if (!(sh.env = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while (environ[i])
	{
		ft_strcpy(sh.env[i], environ[i]);
		++i;
	}
	sh.env[i] = NULL;
	sh.commands = NULL;
	sh.current = NULL;
	return (1);
}
