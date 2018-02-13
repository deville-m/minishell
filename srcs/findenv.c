/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:48:39 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 19:08:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"

char	**findenv(char **environ, const char *envname)
{
	while (*environ)
	{
		if (ft_strnequ(*environ, envname, ft_strlen(envname)))
			return (environ);
		environ++;
	}
	return (NULL);
}
