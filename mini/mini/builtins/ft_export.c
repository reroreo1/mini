/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:02:55 by rezzahra          #+#    #+#             */
/*   Updated: 2022/05/21 21:43:54 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"


char **sortstr(char ***str)
{
	char **arr;
	int i = 0;
	int j = 0;
	char *tmp = NULL;
	arr = *str;
	while(i < lenarr(str))
	{
		j = 0;
		while(j < lenarr(str) - i - 1)
		{
			if (ft_strcmp(arr[i],arr[j]) > 0)
			{
				ft_strcpy(tmp, arr[j]);
				ft_strcpy(arr[j],arr[j + 1]);
				ft_strcpy(arr[j + 1], tmp);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

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

char *replace_env(char **str, int *i, char **env)
{
	int s;
	char *r_str;
	char *key;
	char *key_value = 0;

	s = *i;
	while((*str)[++s] && (*str)[s] != '$' && !iswhite((*str)[s]))
		;
	key = malloc(sizeof(char ) * (s - *i + 1));
	if(!key)
		return (NULL);
	key[0] = 0;
	strncat(key, &(*str)[*i + 1], s - *i - 1);
	if (iswhite((*str)[*i + 1]) || !(*str)[*i + 1] || (*str)[*i + 1] == '$')
		key_value = strdup("$");
	else if (!(key_value = get_var(env, key)))
		key_value = strdup("");
	r_str = malloc(sizeof( char ) * (strlen((*str)) - strlen(key) + strlen(key_value)));
	if(!r_str)
		return (NULL);
	r_str[0] = 0;
	strncat(r_str, (*str), *i);
	strncat(r_str, key_value, strlen(key_value));
	strncat(r_str, *str + *i + strlen(key) + 1, strlen(*str + *i + strlen(key) + 1));
	*i += strlen(key_value);
	free(key);
	free(*str);
	*str = r_str;
	return (r_str);
}

int env_len(char **env)
{
	int i;

	i = -1;

	while (env && env[++i])
		;
	return (i);
}

char **dup_env(char **env)
{
	int i = -1;
	char **r_env;
	
	r_env = malloc(sizeof(char *) * (env_len(env) + 1));
	while (env[++i])
		r_env[i] = strdup(env[i]);
	r_env[i] = 0;
	return (r_env);
}

int env_modi(char *key, char *key_val, char ***env)
{
	int i;
	char *k;

	k = malloc(strlen(key) + 2);
	if (!k)
		return (0);
	*k = 0;
	strcat(k, key);
	strcat(k, "=");
	i = -1;
	while (strncmp((*env)[++i], k, strlen(k)))
		;
	free((*env)[i]);
	(*env)[i] = malloc(strlen(k) + strlen(key_val) + 1);
	if (!(*env)[i])
	{
		free(k);
		return (0);
	}
	(*env)[i][0] = 0;
	strcat((*env)[i],k);
	strcat((*env)[i],key_val);
	free(k);
	return (1);
}

int env_add(char *key, char *key_val, char ***env)
{
	int len;
	char **r_env;
	int i;
	char *r_var;
	
	r_var = get_var(*env, key);
	if (r_var)
	{
		env_modi(key, key_val, env);
		return (1);
	}
	len = env_len(*env);
	r_env = malloc(sizeof(char *) * (len + 2));
	i = -1;
	while ((*env)[++i])
		r_env[i] = strdup((*env)[i]);
	r_env[i] = malloc(sizeof(char *) * (strlen(key) + strlen(key_val) + 2));
	r_env[i][0] = 0;
	strcat(r_env[i], key);
	if (key_val)
		strcat(r_env[i], "=");
	if (key_val)
		strcat(r_env[i], key_val);
	r_env[i + 1] = 0;
	free(*env);
	*env = r_env;
 	return (1);
}

char *replace_env_var(char *str, char **env)
{
	int i;
	char  *r_str;

	i = 0;
	r_str = strdup(str);
	while (r_str[i])
	{
		if (r_str[i] == '\'' )
		{
			while (r_str[++i] != '\'' && r_str[i])
				;
			continue ;
		}
		else if (r_str[i] == '$')
		{
			if(!replace_env(&r_str, &i, env))
				return (NULL);
		}
		else
			i++;
	}
	return (r_str);
}

int ft_export(char **args)
{
	int len = lenarr(args);
	char **arr = NULL;

	if (len == 1 && args[1][0] == '\0')
	{
		arr = sortstr(&env);
		while(*arr++)
			printf("declare -x %s\n",*arr);
	}
	else
	{
		args++;
		while(*args)
		{
			if (ft_strchr(*args, '='))
			{
				if (!env_add(*args, ft_strchr(*args, '=') + 1, &env))
					return (0);
			}
			else if (ft_strchr(*args,'=') && args[ft_strlen(args) - 1] == '=')
			{
				if (!env_add(*args, "", &env))
					return (0);
			}
			else
				if (!env_add(*args, NULL, &env))
					return (0);
			args++;
		}
	}
	return 0;
}
