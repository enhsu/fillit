/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:31:13 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:31:14 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
}
