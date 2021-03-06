/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:52:44 by claudioca         #+#    #+#             */
/*   Updated: 2017/11/29 10:53:13 by claudioca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_nbr_digits(int nbr)
{
	int	i;

	i = 0;
	while (1)
	{
		++i;
		nbr /= 10;
		if (!nbr)
			break ;
	}
	return (i);
}
