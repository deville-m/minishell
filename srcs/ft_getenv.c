/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:28:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 17:24:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

char	*ft_getenv(char *key)
{
	extern char **environ;

	while (*environ)
	{
		if (ft_strnequ(*environ, key, ft_strlen(key)))
			return (*environ + ft_strlen(key) + 1);
		environ++;
	}
	return (NULL);
}
