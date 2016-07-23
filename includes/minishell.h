/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:32:01 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/23 11:25:24 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_env
{
	char	**environ;
	char	*line;
}				t_env;

//environ
char	*ft_get_env(char *str, t_env *e);

#endif
