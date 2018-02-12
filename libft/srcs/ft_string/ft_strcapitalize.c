/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:25:24 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 16:08:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_ctype.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && ft_isalpha(str[i]))
				|| (ft_isalpha(str[i])
					&& (ft_isspace(str[i - 1])
					|| str[i - 1] == '+'
					|| str[i - 1] == '-')))
			str[i] = ft_toupper(str[i]);
		else
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
