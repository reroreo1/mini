/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:03:23 by rezzahra          #+#    #+#             */
/*   Updated: 2022/04/11 03:21:27 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include <stdlib.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

char *finder(char **env,char *cmd);
int	findstr(char *table);

#endif