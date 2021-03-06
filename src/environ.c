/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:19:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/24 17:28:46 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"

void	ft_env(t_env *e)
{
	int	y;

	y = 0;
	while (e->environ[y] != 0)
	{
		ft_putstr(e->environ[y]);
		ft_putchar('\n');
		y++;
	}
}

void	ft_setenv(t_env *e)
{
	int		i;
	char	**tab;
	int		y;
	int		check;

	i = 1;
	while (e->args[i])
	{
		
	}
}

int		search_paths(t_env *e)
{
	t_search	env;

	env.paths = ft_strsplit(ft_getenv("PATH", e), ':');
	env.y = 0;
	while (env.y > -1 && env.paths[env.y] != 0)
	{
		env.dirp = opendir(env.paths[env.y]);
		while ((env.entry = readdir(env.dirp)) != NULL)
		{
			if (strcmp(env.entry->d_name, e->args[0]) == 0)
			{
				env.str = ft_strjoin(env.paths[env.y], "/");
				run_exec(ft_strjoin(env.str, env.entry->d_name), e);
				free(env.str);
				env.str = NULL;
				env.y = -2;
			}
		}
		closedir(env.dirp);
		env.y++;
	}
	free_tab(env.paths);
	free(env.paths);
	env.paths = NULL;
	return (env.y);
}

char	*ft_getenv(char *str, t_env *e)
{
	int	y;

	y = 0;
	while (e->environ[y] != 0)
	{
		if (ft_strstr(e->environ[y], str) != NULL)
			return (&e->environ[y][ft_strlen(str) + 1]);
		y++;
	}
	return (NULL);
}
