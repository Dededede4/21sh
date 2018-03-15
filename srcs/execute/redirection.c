/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabral <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:13:51 by ccabral           #+#    #+#             */
/*   Updated: 2018/03/15 14:00:29 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <execute.h>
#include <token.h>

t_fd_pair	heredoc(t_array *args)
{
	t_fd_pair	fd;

	(void)args;
	fd.to = 0;
	fd.from = 0;
	return (fd);
}

t_fd_pair	redirect_to_fd(t_array *args, char direction)
{
	t_fd_pair	fd;
	t_tree		**children;

	fd.from = (direction - '<') / 2;
	children = (t_tree **)args->begin;
	if (array_size(args) == 1)
	{
		fd.to = *(int *)children[0]->element;
	}
	else
	{
		fd.from = *(int *)children[0]->element;
		fd.to = *(int *)children[1]->element;
	}
	return (fd);
	//if (direction == '>')
		//return (dup2(fd_from, fd_to));
	//return (dup2(fd_to, fd_from));
}

t_fd_pair	redirect_to_file(t_array *args, int mode, char direction)
{
	t_fd_pair	fd;
	int			tmp;
	char		*path;
	t_tree		**children;

	fd.from = (direction - '<') / 2;
	children = (t_tree **)args->begin;
	if (array_size(args) == 1)
		path = ft_strndup(((t_token *)children[0]->element)->begin,
							((t_token *)children[0]->element)->size);
	else
	{
		fd.from = *(int*)children[0]->element;
		path = ft_strndup(((t_token *)children[0]->element)->begin,
							((t_token *)children[0]->element)->size);
	}
	if ((fd.to = open(path, mode, 0644)) < 0)
		return (fd);
	if (direction == '<')
	{
		tmp = fd.to;
		fd.to = fd.from;
		fd.from = tmp;
	}
	tmp = dup(fd.from);
	dup2(fd.to, fd.from);
	close(fd.to);
	fd.to = tmp;
	return (fd);
}

t_fd_pair	redirect(t_tree *tree)
{
	t_fd_pair	ret;

	ret.to = -1;
	ret.from = -1;
	if (branch_equals(tree, GREATER))
		ret = redirect_to_file(tree->children, O_RDWR | O_TRUNC | O_CREAT, '>');
	else if (branch_equals(tree, LESS))
		ret = redirect_to_file(tree->children, O_RDWR | O_TRUNC | O_CREAT, '<');
	else if (branch_equals(tree, GREATERAND))
		ret = redirect_to_fd(tree->children, '>');
	else if (branch_equals(tree, LESSAND))
		ret = redirect_to_fd(tree->children, '<');
	else if (branch_equals(tree, DGREATER))
		ret = redirect_to_file(tree->children, O_RDWR | O_APPEND | O_CREAT, '<');
	else if (branch_equals(tree, DLESS))
		ret = heredoc(tree->children);
	return (ret);
}
