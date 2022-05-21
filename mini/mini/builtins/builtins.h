/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:20:45 by mac               #+#    #+#             */
/*   Updated: 2022/05/22 00:07:34 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FLAG 1
#include "../libft/libft.h"

extern char **env;

// typedef struct s_env{
// 	char *name;
// 	char *value;
// 	struct s_env *next;
// }				t_env;
int		ft_env(char **args);
int		ft_echo(char **args);
int		ft_cd(char **args);
int		ft_exit(char **args);
int		ft_pwd(char **args);
int		ft_unset(char **args);
int		ft_export(char **args);
// int		findstr1(char **table,char str,int len);
int		isalldigit(char *str);
int		lenarr(char **arr);
char	*get_var(char **env, char *key);
void	putendl_fd(char *str, int fd);
char 	*replace_env(char **str, int *i, char **env);
int 	env_len(char **env);
char 	**dup_env(char **env);
int 	env_modi(char *key, char *key_val, char ***env);
int 	env_add(char *key, char *key_val, char ***env);
char 	*replace_env_var(char *str, char **env);


// void	env_add_back(t_env **lst, t_env *new);
// t_env	*env_new(char *name, char *value);
// t_env	*arr_to_ll(char **arr);
#endif