/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 15:31:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "ft_string.h"

int	is_builtin(char **split, char ***env)
{
	if (ft_strequ(split[0], "echo"))
		echo(split);
	else if (ft_strequ(split[0], "setenv"))
	{
		if (split[1] && split[2])
			*env = ft_setenv(*env, split[1], split[2], 1);
		else
			ft_fprintf(2, "usage: setenv envname enval\n");
	}
	else if (ft_strequ(split[0], "unsetenv"))
	{
		if (split[1])
			*env = ft_unsetenv(*env, split[1]);
		else
			ft_fprintf(2, "usage: unsetenv envnamen\n");
	}
	else if (ft_strequ(split[0], "env"))
		ft_env(split, *env);
	else
		return (0);
	/*else if (ft_strequ(split[0], "cd"))*/
	return (1);
}
