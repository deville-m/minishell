/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:24:25 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 19:08:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minishell.h"

void	process_signal_handler(int signo)
{
	extern t_shell sh;

	if (signo == SIGINT)
	{
		if (sh.current_pid)
			kill(sh.current_pid, SIGINT);
		write(1, "\n", 1);
		prompt();
	}
}
