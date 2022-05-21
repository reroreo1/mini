/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:20:12 by mac               #+#    #+#             */
/*   Updated: 2022/05/21 22:18:44 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char **env;

char *get_var(char **env, char *key)
{
	int i;
	char *k;
	int len;
	
	i = 0;
	k = malloc(sizeof(char) * (strlen(key) + 2));
	if (!k)
		return (NULL);
	*k = 0;
	len = strlen(key) + 1;
	strncat(k, key, strlen(key) + 1);
	strcat(k, "=");
	while (env[i])
	{
		if (strncmp(env[i], k, len) == 0)
		{
			free(k);
			return (env[i] + len);
		}
		i++;
	}
	free(k);
	return (NULL);
}

int ft_cd(char **args)
{
	char *pwd;
    if (args[1] == NULL)
        if (get_var("HOME",env) != NULL)
            chdir(get_env("HOME",env));
        else
            ft_putendl("cd: HOME not set");
    else if (args[1][0] == '-' && args[1][1] == '\0')
	{
		pwd = getcwd(NULL, 0);
		printf("%s\n", get_var("OLDPWD",env));
		chdir(get_var("OLDPWD",env));
		env_modi("OLDPWD",pwd, &env);
		free(pwd);
	}
	else if (args[1][0] == '~')
		chdir(get_var("HOME",env));
	else if (args[1][0] == '.' && args[1][1] == '\0')
		chdir(get_var("PWD",env));
	else
	{	
		chdir(args[1]);
		perror("");
		exit(0);
	}
	return 0;	         
}