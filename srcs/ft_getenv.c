/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:28:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 17:23:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "ft_string.h"

char	*ft_getenv(char *key)
{
	extern t_shell	sh;
	size_t			i;

	i = 0;
	while (sh.env[i])
	{
		if (ft_strnequ(sh.env[i], key, ft_strlen(key)))
			return (sh.env[i] + ft_strlen(key) + 1);
		++i;
	}
	return (NULL);
}
