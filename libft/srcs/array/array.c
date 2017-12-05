/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:06:40 by claudioca         #+#    #+#             */
/*   Updated: 2017/12/05 11:33:54 by claudioca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <array.h>

t_array			*array_create(size_t element_size, size_t nbr_elements)
{
	t_array	*array;

	if (!(array = malloc(sizeof(t_array))))
		return (0);
	array->capacity = element_size * nbr_elements;
	if (!(array->begin = malloc(array->capacity + element_size)))
	{
		free(array);
		return (0);
	}
	array->end = (unsigned char *)array->begin + element_size;
	array->element_size = element_size;
	ft_bzero(array->begin, array->capacity + element_size);
	return (array);
}

void			array_clear(t_array *array, t_freef free_func)
{
	void	*it;

	it = array->begin;
	while (it != array->end)
	{
		free_func(it);
		ft_bzero(it, array->element_size);
		it = (unsigned char *)it + array->element_size;
	}
	array->end = (unsigned char *)array->begin + array->element_size;
}

void			array_free(t_array *array, t_freef free_func)
{
	void	*it;

	it = array->begin;
	while (it != array->end)
	{
		free_func(it);
		it = (unsigned char *)it + array->element_size;
	}
	free(array->begin);
	free(array);
}

int				array_increase_capacity(t_array *array)
{
	void	*buffer;

	if (!(buffer = malloc(array->capacity * 2)))
		return (0);
	ft_memcpy(buffer, array->begin, array->capacity);
	array->end = array->begin;
	free(array->begin);
	array->begin = buffer;
	array->capacity += array->capacity;
	return (1);
}

void			*array_push_back(t_array *array, void *element)
{
	if (array->capacity <= array->end - array->begin + array->element_size
		 && !array_increase_capacity(array))
		return (0);
	ft_memcpy(array->end, element, array->element_size);
	array->end = (unsigned char *)array->end + array->element_size;
	return ((unsigned char *)array->end - array->element_size);
}
