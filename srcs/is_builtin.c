/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 20:06:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "ft_string.h"

int	is_builtin(char **split)
{
	if (ft_strequ(split[0], "echo"))
		echo(split);
	else if (ft_strequ(split[0], "setenv"))
	{
		if (split[1] && split[2])
			ft_setenv(split[1], split[2], 1);
		else
			ft_fprintf(2, "usage: setenv envname enval\n");
	}
	else
		return (0);
	/*
	else if (ft_strequ(split[0], "cd"))
	else if (ft_strequ(split[0], "unsetenv"))*/
	return (1);
}
