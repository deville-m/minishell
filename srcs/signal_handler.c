/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:57:40 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/16 15:40:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minishell.h"
#include "ft_printf.h"

void	signal_handler(int signo)
{
	extern char **g_env;

	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		prompt(g_env);
	}
}

void	proc_signal_handler(int signo)
{
	extern int g_pid;

	if (signo == SIGINT)
	{
		if (kill(g_pid, SIGINT))
			ft_fprintf(2, "Could not kill process\n");
		else
			write(1, "\n", 1);
	}
}
