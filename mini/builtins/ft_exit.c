/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:03:48 by mac               #+#    #+#             */
/*   Updated: 2022/05/21 19:20:28 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int lenarr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}
int isalldigit(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_exit(char **args)
{
    int i;
    int value = 0;
    
    i = 0;
    if (lenarr(args) == 1 && isalldigit(args[1]))
    {
        putendl_fd("exit", 1);
        if (ft_atoi(args[0]) > 255)
            exit(ft_atoi(args[1]));
        else
            exit(ft_atoi(args[1]));
        exit(ft_atoi(args[1] % 255));
    }
    else if (lenarr(args) == 1 && isalldigit(args[1]) == 0)
    {
        putendl_fd("exit", 1);
        printf("exit: %s numeric argument required\n", args[1]);
        exit(255);
    }
    else if (lenarr(args) > 1)
    {
        putendl_fd("exit", 1);
        printf("exit: too many arguments\n");
        exit(255);
    }
    exit(0);
}