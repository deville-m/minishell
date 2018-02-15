/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:14:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:26:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_echo(char **args)
{
	size_t i;

	if (!args[0])
	{
		ft_printf("\n");
		return ;
	}
	i = 0;
	while (args[i + 1])
		ft_printf("%s ", args[i++]);
	ft_printf("%s\n", args[i]);
}
