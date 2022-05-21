/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:20:04 by mac               #+#    #+#             */
/*   Updated: 2022/05/21 19:21:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int isn(char *str)
{
    int i = 0;
    if (str[i] == '-')
    {
        i++;
        while(str[i] == 'n' && str[i])
            i++;
        if (str[i] == '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}
void putstr_fd_flag(char *str,int fd,int flag)
{   
    while(*str)
    {
        if (flag  == 1)
        {
            if (*str == '\n')
                str++;
            else
                write(1,str,fd);
        }
        else
            write(1,str,fd);
        str++;
    }
}

int ft_echo(char **args)
{
    int i = 0;
    int flag = 0;

    while (args[i])
    {
        if (isn(args[i]) || ft_strcmp(args[i], "-n") == 0)
        {
            flag = 1;
            i++;
        }
        else
        {
            putstr_fd_flag(args[i],1,flag);
            if (args[i + 1] != NULL)
                write(1," ",1);
        i++;
    }
    if (flag != 1)
        write(1,"\n",1);
    }
    return 0;
}
    
        
    
    