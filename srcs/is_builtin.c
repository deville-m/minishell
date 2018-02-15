/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:37:42 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "ft_string.h"

int	is_builtin(char **current)
{
	if (ft_strequ(current[0], "exit"))
		ft_exit();
	else if (ft_strequ(current[0], "echo"))
		echo(current);
	else if (ft_strequ(current[0], "setenv"))
		(current[1]) ? ft_setenv(current[1], current[2], 1) :
					ft_fprintf(2, "usage: setenv envname [enval]\n");
	else if (ft_strequ(current[0], "unsetenv"))
		(current[1]) ? ft_unsetenv(current[1]) :
					ft_fprintf(2, "usage: unsetenv envnamen\n");
	else if (ft_strequ(current[0], "env"))
		ft_env();
	else if (ft_strequ(current[0], "cd"))
		ft_cd(current[1]);
	else
		return (0);
	return (1);
}
