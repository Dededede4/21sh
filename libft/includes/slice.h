/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccabral <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:33:05 by ccabral           #+#    #+#             */
/*   Updated: 2018/03/22 11:42:19 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H

typedef struct	s_slice
{
	char const	*ptr;
	int			size;
}				t_slice;

t_slice			make_slice(char const *ptr, int size);
t_slice			error_slice(void);
t_slice			slice_from_pointers(char const *begin, char const *end);

#endif
