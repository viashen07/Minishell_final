/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:37:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/23 11:25:11 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_line(t_env *e)
{
	
}

void	begin_shell(t_env *e)
{
	ft_putstr("$> ");
	get_next_line(0, &e->line);
	if (ft_strcmp(e->line, "exit") != 0)
	{
		process_line(e);
		free(e->line);
		e->line = NULL;
		begin_shell(e);
	}
}

int		main(void)
{
	t_env		e;
	extern char	**environ;

	e.environ = environ;
	begin_shell(t_env *e);
	return (1);
}
