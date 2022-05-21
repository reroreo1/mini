/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:23:47 by rezzahra          #+#    #+#             */
/*   Updated: 2022/05/21 19:03:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
// t_env	*ft_envnew(char *name,char *value)
// {
// 	t_env	*new;

// 	new = (t_env *)malloc(sizeof(t_env));
// 	new->name = name;
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
// }

// t_env	*env_last(t_env *lst)
// {
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 		return (lst);
// 	}
// 	return (NULL);
// }

// void	env_add_back(t_env **lst, t_env *new)
// {
// 	t_env	*last;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		new->next = NULL;
// 		return ;
// 	}
// 	last = env_last(*lst);
// 	last->next = new;
// }

t_env *arr_to_ll(char **arr)
{
	int i = 1;
	int j = 0;
	int len = lenarr(arr);
	t_env *head = NULL;
	t_env *tmp = NULL;
	head = ft_envnew(ft_substr(arr[0], 0, ft_strchr(arr[0], '=') - arr[0]),ft_substr(arr[0], ft_strchr(arr[0], '=') + 1, ft_strlen(arr[0])));
	while(arr[i])
	{
		if (ft_strchr(arr[i], '=') != NULL)
			tmp = ft_envnew(ft_substr(arr[i], 0, ft_strchr(arr[i], '=') - arr[i]),ft_substr(arr[i], ft_strchr(arr[i], '=') + 1, ft_strlen(arr[i])));
		env_add_back(&head, tmp);
		i++;
	}
	return head;
}