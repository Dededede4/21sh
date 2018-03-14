/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:50:24 by claudioca         #+#    #+#             */
/*   Updated: 2018/03/14 18:58:33 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <shellma.h>
#include <execute.h>
#include <signal_handlers.h>
#include <ft_printf.h>
#include <token.h>
#include <environment.h>

int		command_dispatch(char **argv, char **env, char const *who)
{
	void const	*tmp;

	if (ft_strchr(argv[0], '/'))
		return (invoke(argv[0], argv, env, who));
	if ((tmp = get_builtin_command(argv[0])))
		return (invoke_builtin(tmp, argv));
	return (invoke(command_name_lookup(argv[0]), argv, env, who));
	return (127);
}

int		branch_is_redirection(t_tree *tree)
{

		return (branch_equals(tree, GREATER)
				|| branch_equals(tree, DGREATER)
				|| branch_equals(tree, GREATERAND)
				|| branch_equals(tree, LESS)
				|| branch_equals(tree, DLESS)
				|| branch_equals(tree, LESSAND));
}

int		collect_args(t_tree **begin, t_tree **end, t_array *args)
{

	char		*tmp;

	while (begin != end)
	{
		if (branch_is_redirection(*begin))
		{
			ZERO_IF_FAIL(redirect(*begin));
		}
		else
		{
			tmp = token_get_value((*begin)->element);
			if (!tmp || !(array_push_back(args, &tmp)))
			{
				free(tmp);
				array_free(args, (t_freef) & free_wrapper);
				return (0);
			}
		}
		++begin;
	}
	return (1);
}

int		execute_simple_command(t_tree *tree)
{
	t_array		*args;
	int			ret;

	if (!(args = array_create(sizeof(char *), 16)))
		return (1);
	if (!collect_args((t_tree **)tree->children->begin,
				(t_tree **)tree->children->end, args))
		return (1);
	ret = command_dispatch((char **)args->begin, get_environment(),
			"./21sh");
	array_free(args, (t_freef) & free_wrapper);
	return (ret);
}

int		execute_commands(t_tree *tree)
{
	t_tree		**child;
	int			ret;

	child = (t_tree **)tree->children->begin;
	while (child != tree->children->end)
	{
		if (*child)
			ret = execute_simple_command(*child);
		++child;
	}
	return (ret);
}

int		execute(t_tree *tree)
{
	int	ret;

	ret = 0;
	if (!tree)
		return (0);
	ret = dispatch_branch(tree);
	tree_free(tree, (t_freef) & noop);
	return (ret);
}
