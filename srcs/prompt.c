/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:44:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 18:34:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "path.h"

void	prompt(void)
{
	char *res;

	if (!(res = getcwd(NULL, 0)))
		ft_printf("C'est la merd\n");
	else
		ft_printf("%s $> ", ft_basename(res));
	free(res);
}
