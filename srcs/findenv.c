/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:48:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:26:08 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

char	*findenv(const char *envname, int *offset)
{
	extern t_shell	sh;
	size_t			i;

	i = 0;
	while (sh.env)
	{
		if (ft_strnequ(sh.env[i], envname, ft_strlen(envname)))
		{
			if (offset)
				*offset = i;
			return (sh.env[i]);
		}
		++i;
	}
	return (NULL);
}
