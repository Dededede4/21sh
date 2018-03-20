/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabral <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:56:11 by ccabral           #+#    #+#             */
/*   Updated: 2018/03/20 15:17:15 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lexer.h>
#include <token.h>

static int	lex_simple_redirection(t_array *tokens, char const *input,
																int start)
{
	if (input[start] == '<')
	{
		ZERO_IF_FAIL(add_token(tokens, LESS, input + start, 1));
	}
	else if (input[start] == '>')
	{
		ZERO_IF_FAIL(add_token(tokens, GREATER, input + start, 1));
	}
	else
		return (0);
	return (1);
}

static int	heredoc_token_size(char const *input, int start,
								char const *eof_begin, int eof_size)
{
	int	pos;

	pos = 0;
	while (input[start + pos])
	{
		if (input[start + pos] == '\n')
		{
			if (ft_strnequ(input + start + pos + 1, eof_begin, eof_size))
				return (pos + 1);
		}
		++pos;
	}
	return (0);
}

static int	lex_heredoc(t_array *tokens, t_slice input, char *const *heredoc)
{
	char const	*eof_token_begin;
	int			eof_token_size;
	int			pos;

	(void)heredoc;
	while (input.ptr[input.size] && ft_is_whitespace(input.ptr[input.size]))
		++input.size;
	eof_token_begin = input.ptr + input.size;
	eof_token_size = 0;
	while (input.ptr[input.size] && input.ptr[input.size] != '\n')
	{
		++eof_token_size;
		++input.size;
	}
	if (input.ptr[input.size])
		++input.size;
	ZERO_IF_FAIL(pos = heredoc_token_size(input.ptr, input.size,
						eof_token_begin, eof_token_size));
	ZERO_IF_FAIL(add_token(tokens, TOKEN, input.ptr + input.size, pos));
	return (input.size + pos + eof_token_size + 1);
}

int			lex_redirection(t_array *tokens, t_slice input, char *const *heredoc)
{
	if (input.ptr[input.size] == '<' && input.ptr[input.size + 1] == '<')
	{
		ZERO_IF_FAIL(add_token(tokens, DLESS, input.ptr + input.size, 2));
		input.size += 2;
		return (lex_heredoc(tokens, input, heredoc));
	}
	else if (input.ptr[input.size] == '<' && input.ptr[input.size + 1] == '&')
	{
		ZERO_IF_FAIL(add_token(tokens, LESSAND, input.ptr + input.size, 2));
	}
	else if (input.ptr[input.size] == '>' && input.ptr[input.size + 1] == '>')
	{
		ZERO_IF_FAIL(add_token(tokens, DGREATER, input.ptr + input.size, 2));
	}
	else if (input.ptr[input.size] == '>' && input.ptr[input.size + 1] == '&')
	{
		ZERO_IF_FAIL(add_token(tokens, GREATERAND, input.ptr + input.size, 2));
	}
	else
		return (lex_simple_redirection(tokens, input.ptr, input.size));
	return (2);
}
