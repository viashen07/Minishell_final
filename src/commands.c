/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:14:14 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/24 16:48:23 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_env *e)
{
	int		i;
	char	*str;

	i = 0;
	while (e->args[++i] != 0)
	{
		if (e->args[i][0] == '$')
		{
			str = ft_getenv(&e->args[i][1], e);
			if (str != NULL)
			{
				ft_putstr(str);
				ft_putchar(' ');
			}
		}
		else
		{
			ft_putstr(e->args[i]);
			ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}
