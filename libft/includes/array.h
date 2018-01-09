/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:49:51 by claudioca         #+#    #+#             */
/*   Updated: 2018/01/09 12:15:17 by ccabral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <libft.h>

typedef struct	s_array
{
	void	*begin;
	void	*end;
	size_t	element_size;
	size_t	capacity;
}				t_array;

t_array			*array_create(size_t element_size, size_t nbr_elements);
void			array_clear(t_array *array, t_freef free_func);
void			array_free(t_array *array, t_freef free_func);
int				array_increase_capacity(t_array *array);
void			*array_push_back(t_array *array, void *element);
void			*array_insert(t_array *array, void *where, void *element);
void			*array_insert_sorted(t_array *array, void *element,
														t_cmpf cmpf);
void			array_apply(t_array *array, void *args, t_applyf);
void			array_apply_reverse(t_array *array, void *args, t_applyf);
void			*array_apply_until(t_array *array, void *args,
											t_applyf_until applyf);
void			array_sort(t_array *array, t_cmpf cmpf);
void			*array_find_insertion_point(t_array *array, void const *element,
																t_cmpf cmpf);
void			*array_find_sorted(t_array *array, void const *element,
																t_cmpf cmpf);
void			*array_find(t_array *array, void *data, t_cmpf cmpf);
void			array_remove(t_array *array, void *element, t_freef freef);
void			array_remove_if(t_array *array, void const *data,
									t_freef freef, t_predf predicate);
t_array			*array_copy(t_array const *src, void *args,
										t_cpyf cpyf, t_freef);

#endif
