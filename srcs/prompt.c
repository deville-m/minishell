/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:44:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 17:42:25 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "ft_printf.h"
#include "path.h"

void	prompt(char **env)
{
	char *res;

	if ((res = ft_getenv("PWD", env)))
		ft_printf("%s $> ", ft_basename(res));
	else if ((res = getcwd(NULL, 0)))
	{
		ft_printf("%s $> ", ft_basename(res));
		free(res);
	}
	else
		ft_printf("No Directory $>");
}
