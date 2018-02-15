/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:55:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/15 18:38:02 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

typedef struct	s_shell
{
	char		**env;
	char		**commands;
	char		**current;
	pid_t		current_pid;
}				t_shell;

t_shell	sh;

void	prompt(void);
char	**process_input(char *input, char **av, char **env);
char	*getpath(char *bin_name);
int		is_builtin(char **current);
void	deltab(char **tab);

/*
** Environnement Related
*/

int		init_shell(void);
char	*findenv(const char *envname, int *offset);
char	*ft_getenv(char *key);

/*
** Builtins
*/

void	echo(char **args);
void	ft_exit(void);
void	ft_cd(char *directory);
void	ft_env(void);
int		ft_setenv(const char *name, const char *val, int overwrite);
int		ft_unsetenv(const char *name);

#endif
