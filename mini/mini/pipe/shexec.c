/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:20:22 by rezzahra          #+#    #+#             */
/*   Updated: 2022/04/10 18:20:31 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int findstr(char *table)
{
	int i = 0;
	while (table[i])
	{
		if (ft_strncmp(table[i], "PATH=",5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char *finder(char **env,char *cmd)
{
	char **path = ft_split(ft_substr(env[findstr(env)],5,ft_strlen(env[findstr(env)]) - 5), ':');
	char *tmp;

	while(*path)
	{
		tmp = ft_strjoin(*path, "/");
		tmp = ft_strjoin(tmp, cmd);
		if (access(tmp, F_OK) == 0)
			return tmp;
		free(tmp);
		path++;
	}
	return 0;
}