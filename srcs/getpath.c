/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:29:01 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 14:12:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "ft_string.h"
#include "ft_printf.h"

char	*curr_dir(char *bin_name)
{
	char *tmp;

	if (!(tmp = ft_strjoin("./", bin_name)))
		return (NULL);
	if (access(tmp, F_OK))
		return (tmp);
	free(tmp);
	return (NULL);
}

char	*find_bin(char *bin_name, char **split)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		if (!(tmp = ft_strnjoin(3, split[i], "/", bin_name)))
			return (NULL);
		if (!access(tmp, F_OK))
			return (tmp);
		free(tmp);
		++i;
	}
	return (NULL);
}

char	*getpath(char *bin_name, char **env)
{
	char	**split;
	char	*path;

	if (!(path = ft_getenv("PATH", env)))
		return (NULL);
	if (!*path)
		return (curr_dir(bin_name));
	split = ft_strsplit(path, ':');
	if (!(path = find_bin(bin_name, split)) && !access(bin_name, F_OK))
		path = ft_strdup(bin_name);
	deltab(split);
	return (path);
}
