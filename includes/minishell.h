/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:55:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/14 17:11:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
