/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:20:19 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 17:22:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	ft_exit(void)
{
	extern t_shell sh;

	deltab(sh.env);
	deltab(sh.commands);
	deltab(sh.current);
	exit(0);
}
