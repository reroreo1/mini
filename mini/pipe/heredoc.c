/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:58:40 by rezzahra          #+#    #+#             */
/*   Updated: 2022/05/12 00:25:42 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
void he1redoc(char *delimiter)
{
	char *line = NULL;
	if (!delimiter)
		printf("minishell: heredoc: syntax error\n");
	else
	{
		while(ft_strcmp(line, ft_strjoin(delimiter,"\n")) != 0)
			line = ft_strjoin(line, get_next_line(0));
		printf("%s", line);
	}
}