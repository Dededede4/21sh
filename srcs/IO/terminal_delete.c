/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:50:47 by claudioca         #+#    #+#             */
/*   Updated: 2018/01/13 19:07:25 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_printf.h>
#include <io.h>

int						terminal_delete(t_terminal *terminal, int c)
{
	c = CTRL_H;
	if (terminal->cursor == terminal->prompt_size)
		return (1);
	write(terminal->tty, &c, 1);
	terminal_command(DELETE, 1);
	while (is_middle_of_unicode(
			terminal->line->buffer[terminal->cursor
								- terminal->prompt_size - 1]))
	{
		string_delete(terminal->line,
				terminal->cursor - terminal->prompt_size - 1);
		terminal->cursor--;
	}
	string_delete(terminal->line,
			terminal->cursor - terminal->prompt_size - 1);
	terminal->cursor--;
	return (1);
}

int						terminal_delete_word(t_terminal *terminal, int c)
{
	while (terminal->cursor != terminal->prompt_size &&
			ft_is_whitespace(terminal->line->buffer
				[terminal->cursor - terminal->prompt_size - 1]))
		terminal_delete(terminal, c);
	while (terminal->cursor != terminal->prompt_size &&
			!ft_is_whitespace(terminal->line->buffer
				[terminal->cursor - terminal->prompt_size - 1]))
		terminal_delete(terminal, c);
	return (1);
}

int						terminal_delete_until_eol(t_terminal *terminal, int c)
{
	int		current_position;

	current_position = terminal->cursor;
	terminal_eol(terminal, c);
	while (terminal->cursor > current_position)
		terminal_delete(terminal, CTRL_H);
	return (1);
}

int						terminal_kill_line(t_terminal *terminal, int c)
{
	terminal_bol(terminal, c);
	terminal_delete_until_eol(terminal, c);
	write(0, "\n", 1);
	print_prompt(terminal);
	terminal->cursor = terminal->prompt_size;
	return (1);
}

int						terminal_cancel_line(t_terminal *terminal, int c)
{
	(void)c;
	write(terminal->tty, "\n", 1);
	terminal_command(MOVE_LEFT, terminal->cursor);
	string_clear(terminal->line);
	terminal->cursor = terminal->prompt_size;
	write(terminal->tty, terminal->prompt, terminal->prompt_size);
	return (1);
}
