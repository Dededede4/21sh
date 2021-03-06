/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:41:32 by claudioca         #+#    #+#             */
/*   Updated: 2018/03/20 19:29:33 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <shellma.h>
#include <array.h>
#include <token.h>
#include <ft_printf.h>

int			lex_quote(t_array *tokens, t_slice input)
{
	int	pos;

	pos = input.size + 1;
	while (input.ptr[pos] && input.ptr[pos] != input.ptr[input.size])
		++pos;
	if (input.ptr[pos] != input.ptr[input.size])
		return (-1);
	if (add_token(tokens, TOKEN, input.ptr + input.size, pos - input.size))
		return (pos + 1);
	return (-1);
}

int			lex_operator(t_array *tokens, t_slice input, char const **heredoc)
{
	int	ret;

	ret = 0;
	if (input.ptr[input.size] == ';')
		ret = add_token(tokens, SEMICOLON, input.ptr + input.size, 1);
	else if (input.ptr[input.size] == '&')
		ret = add_token(tokens, AND, input.ptr + input.size, 1);
	else if (input.ptr[input.size] == '|')
		ret = add_token(tokens, PIPE, input.ptr + input.size, 1);
	else if (input.ptr[input.size] == '<' || input.ptr[input.size] == '>')
		ret = lex_redirection(tokens, input, heredoc);
	if (ret)
		return (input.size + ret);
	return (-1);
}

int			lex_token(t_array *tokens, t_slice input, int pos)
{
	while (input.ptr[pos])
	{
		if (input.ptr[pos] == '\\')
		{
			++pos;
			if (!input.ptr[pos])
				break ;
		}
		else if (token_delimiter(input.ptr[pos]))
			break ;
		++pos;
	}
	if (add_token(tokens, TOKEN, input.ptr + input.size, pos - input.size))
		return (pos);
	return (-1);
}

int			lex_digit(t_array *tokens, t_slice input)
{
	int		pos;

	pos = input.size;
	while (ft_isdigit(input.ptr[pos]))
		++pos;
	if (input.ptr[pos] == '<' || input.ptr[pos] == '>')
	{
		if (add_token(tokens, IO_NUMBER, input.ptr + input.size,
												pos - input.size))
			return (pos);
		return (-1);
	}
	return (lex_token(tokens, input, pos));
}

int			lex_text(t_array *tokens, t_slice input, char const **heredoc)
{
	char const	*end;

	end = *heredoc;
	if (*end)
		--end;
	while (input.ptr + input.size < end)
	{
		if (ft_is_whitespace(input.ptr[input.size]))
			++input.size;
		else if (!input.ptr[input.size])
			break ;
		else if (token_newline(input.ptr[input.size]))
			input.size = push_newline_token(tokens, input.ptr, input.size);
		else if (token_operator(input.ptr[input.size]))
			input.size = lex_operator(tokens, input, heredoc);
		else if (ft_isdigit(input.ptr[input.size]))
			input.size = lex_digit(tokens, input);
		else if (token_quote(input.ptr[input.size]))
			input.size = lex_quote(tokens, input);
		else
			input.size = lex_token(tokens, input, input.size);
		if (input.size == -1)
			return (-1);
	}
	return (1);
}
