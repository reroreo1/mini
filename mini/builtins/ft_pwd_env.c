/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:23:50 by mac               #+#    #+#             */
/*   Updated: 2022/05/21 19:02:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void putendl_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
    write(fd, "\n", 1);
}

int ft_env(char **args)
{
    char **tmp;

    tmp = env;
    while (*tmp)
        printf("%s\n", tmp++);
    return (0);
}

// int findstr1(char **table,char str,int len)
// {
// 	int i = 0;
// 	while (table[i])
// 	{
// 		if (ft_strncmp(table[i], str,len) == 0)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

int ft_pwd(char **args)
{
    char *pwd;

    pwd = getcwd(NULL,0);
    if (pwd)
        putendl_fd(pwd,1);
    else
    {
        if (get_var(env,"PWD") != NULL)
            putendl_fd(get_var(env,"PWD"),1);
    }
    free(pwd);
    return (0);
}


