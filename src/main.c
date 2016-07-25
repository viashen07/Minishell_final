/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:37:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/25 13:43:36 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_commands(t_env *e)
{
	if (ft_strcmp(e->args[0], "cd") == 0)
	{
		if (!e->args[1] || chdir(e->args[1]) != 0)
			ft_putstr("cd: directory not found\n");
	}
	else if (ft_strcmp(e->args[0], "echo") == 0)
		ft_echo(e);
	else if (ft_strcmp(e->args[0], "setenv") == 0)
		;
	else if (ft_strcmp(e->args[0], "unsetenv") == 0)
		;
	else if (ft_strcmp(e->args[0], "env") == 0)
		ft_env(e);
	else
		return (search_paths(e));
	return (0);
}

void	process_line(t_env *e)
{
	e->args = ft_strsplit(e->line, ' ');
	if (search_commands(e) < 0)
		;
}

void	begin_shell(t_env *e)
{
	ft_putstr("$> ");
	get_next_line(0, &e->line);
	if (strcmp(e->line, "exit") != 0)
	{
		if (strcmp(e->line, "") != 0)
		{
			process_line(e);
			free(e->line);
			e->line = NULL;
			if (e->args)
			{
				free_tab(e->args);
				free(e->args);
			}
			e->args = NULL;
		}
		begin_shell(e);
	}
	free(e->line);
	e->line = NULL;
}

int		main(void)
{
	t_env		e;
	extern char	**environ;

	e.environ = environ;
	begin_shell(&e);
	return (1);
}
