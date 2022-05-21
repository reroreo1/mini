/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:09:24 by mac               #+#    #+#             */
/*   Updated: 2022/05/22 00:23:59 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char **delete_var(char **env,char *var)
{
		int i = -1;
	char **r_env;
	
	r_env = malloc(sizeof(char *) * (env_len(env) + 1));
	while (env[++i])
	{
		if (strncmp(env[i], var, ft_strlen(var)) != 0)
			r_env[i] = ft_strdup(env[i]);
	}
	r_env[i] = 0;
	return (r_env);	
}
void is_valid(char *arg)
{
	if (isalldigit(arg))
		return 0;
	while(*args++)
	{
		if (*arg != '_' || ft_isalpha(*arg) == 0)
			return 0;
	}
	return 1;	
}
int ft_unset(char **args)
{
	args++;
	while(*args)
	{
		if (is_valid(*args))
			env = delete_var(env, *args);
		else
			ft_putendl(" unset: '%s': not a valid identifier", *args);
		args++;
	}
	return (0);
}
    
    

