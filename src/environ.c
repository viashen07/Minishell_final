/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:19:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/23 11:25:18 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(char *str, t_env *e)
{
	int	y;

	y = 0;
	while (environ[y] != 0)
	{
		if (ft_strstr(e->environ[y], str) != NULL)
			return (&e->environ[y][ft_strlen(str) + 1]);
		y++;
	}
	return (NULL);
}
