/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:34:04 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 17:47:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	deltab(char **tab)
{
	char **cpy;

	if (!tab)
		return (1);
	cpy = tab;
	while (*cpy)
		free(*cpy++);
	free(tab);
	return (1);
}
