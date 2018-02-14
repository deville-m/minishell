/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:14:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 19:29:47 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void echo(char **split)
{
	size_t i;

	if (!split[1])
	{
		ft_printf("\n");
		return ;
	}
	i = 1;
	while(split[i + 1])
		ft_printf("%s ", split[i++]);
	ft_printf("%s\n", split[i]);
}
