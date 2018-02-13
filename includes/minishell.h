/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:55:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/13 20:01:03 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		process_input(char *input, char **av);
char	*ft_getenv(char *env);
int		ft_setenv(const char *envname, const char *enval, int overwrite);
char	**findenv(char **environ, const char *envname);
char	*getpath(char *bin_name);
void	prompt(void);
int		is_builtin(char **split);
void	echo(char **split);
void	deltab(char **tab);
