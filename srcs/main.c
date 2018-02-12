/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:10:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/12 17:26:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_string.h"

int main()
{
	char	*line;
//	int		fid;

	while (42)
	{
		ft_printf("$wag$hell->\t");
		get_next_line(0, &line);
		if (ft_strncmp(line, "echo", 4) == 0)
			ft_printf("%s\n", line + 4);
		free(line);
	}
}
