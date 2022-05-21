/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:20:12 by mac               #+#    #+#             */
/*   Updated: 2022/05/21 19:04:29 by mac              ###   ########.fr       */
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
    if (args[1] == NULL)
        if (get_var("HOME",env) != NULL)
            chdir(get_env("HOME",env));
        else
            ft_putendl("cd: HOME not set");
    else if (args[0][0] == '-' && args[0][1] == '\0')
              
}