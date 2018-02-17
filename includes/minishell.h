/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:55:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 14:34:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

int		g_pid;
char	**g_env;

void	proc_signal_handler(int signo);
void	signal_handler(int signo);
char	**process_input(char *input, char **av, char **env);
char	**ft_cd(char *split, char **env);
void	ft_env(char **split, char **env);
char	*ft_getenv(char *key, char **env);
char	**ft_setenv(
				char **env,
				const char *envname,
				const char *enval,
				int overwrite);
char	**ft_unsetenv(
				char **env,
				const char *envname);
char	**findenv(char **environ, const char *envname);
char	*getpath(char *bin_name, char **environ);
void	prompt(char **env);
int		is_builtin(char **split, char ***env);
void	echo(char **split);
void	deltab(char **tab);

#endif
